/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:42:49 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/29 16:20:14 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"


t_display	*init_graph(char *title, t_gridinfo *grid)
{
	t_display	*n;

	if (title == NULL)
		return (NULL);
	n = malloc(sizeof(t_display));
	if (!n)
		return (NULL);
	n->mlx = mlx_init();
	if (!n->mlx)
		return (free(n), NULL);
	n->window = mlx_new_window(n->mlx, WIN_W, WIN_H, title);
	if (!n->window)
		return (free(n->mlx), free(n), NULL);
	n->img = malloc(sizeof(t_img_data));
	if (!n->img)
		return (free(n->mlx), free(n->window), free(n), NULL);
	n->img->img = NULL;
	return (n);
}

t_img_data	*new_image(t_display *dis)
{
	t_img_data	*img;

	img = dis->img;
	if (img->img)
		mlx_destroy_image(dis->mlx, dis->img->img);
	img->img = mlx_new_image(dis->mlx, WIN_W, WIN_H);
	if (!img->img)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	if (!img->addr)
		return (free(img->img), free(img), NULL);
	dis->img = img;
	return (img);
}

void 	free_display(t_display *dis)
{
	mlx_destroy_image(dis->mlx, dis->img->img);
	mlx_destroy_window(dis->mlx, dis->window);
	free(dis->mlx);
	if (dis->img)
		free(dis->img);
	free(dis);
}

void	pixel_put_img(t_img_data *img, int x, int y, int color)
{
	void	*dst;
	dst = img->addr + (y * img->len) + x * (img->bpp / 8);
	*((int *)dst) = color;
}

double	draw_line(t_display *dis, t_coord start, t_coord end, int color)
{
	double		l_size;
	t_coord		delta;

	l_size = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2));
	delta.x = (end.x - start.x) / l_size;
	delta.y = (end.y - start.y) / l_size;
	while (l_size > 0)
	{
		if ((start.x >= 0 && start.y >= 0) && (start.x < WIN_W && start.y < WIN_H))
			pixel_put_img(dis->img, start.x, start.y, color);
		start.x += delta.x;
		start.y += delta.y;
		l_size--;
	}
	return (l_size);
}

