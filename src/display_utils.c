/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:42:49 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/20 14:49:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"


t_display	*init_graph(char *title, t_grid *grid)
{
	t_display	*n;
	t_img		*img;
	int			*endian;

	if (title == NULL)
		return (NULL);
	n = malloc(sizeof(t_display));
	if (!n)
		return (NULL);
	n->mlx = mlx_init();
	if (!n->mlx)
		return (free(n), NULL);
	n->v_norm = create_vector(B_X, B_Y, B_Z);
	n->win = size_of_grid(grid, n);
	n->window = mlx_new_window(n->mlx, n->win.x, n->win.y, title);
	if (!n->window)
		return (free(n->mlx), free(n), NULL);
	n->img = malloc(sizeof(t_img_data));
	if (!n->img)
		return (free(n->img),free(n->mlx), free(n->window), free(n), NULL);
	n->img->img = mlx_new_image(n->mlx, n->win.x, n->win.y);
	if (!n->img->img)
		return (free(n->img),free(n->mlx), free(n->window), free(n), NULL);
	img = &n->img->img;
	endian = &n->img->endian;
	n->img->addr = mlx_get_data_addr(n->img->img, &n->img->bpp, &n->img->len, &n->img->endian);
	return (n);
}
void	pixel_put_img(t_img_data *img, int x, int y, int color)
{
	void	*dst;
	dst = img->addr + (y * img->len) + x * (img->bpp / 8);
	*((int *)dst) = color;
}

double	draw_line(t_display *dis, t_coord start, t_coord end)
{
	double		l_size;
	t_coord		delta;

	l_size = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2));
	delta.x = (end.x - start.x) / l_size;
	delta.y = (end.y - start.y) / l_size;
	while (l_size > 0)
	{
		if ((start.x >= 0 && start.y >= 0) && (start.x < dis->win.x && start.y < dis->win.y))
			pixel_put_img(dis->img, start.x, start.y, 0x336633);
		start.x += delta.x;
		start.y += delta.y;
		l_size--;
	}
	return (l_size);
}

int	height_color(t_grid *grid, int y)
{
	double	p_max;

	p_max = ((double) grid->y_max)/((double) y);
	if (p_max <= 0.50)
		return (0xffff00 + (1-p_max)*255);
	else
		return(0xffff00 - (p_max)*255);
}

t_coord	size_of_grid(t_grid *grid, t_display *dis)
{
	t_vector	sum_v;
	t_coord		size;

	sum_v.x = -((grid->x_max - 1) + (grid->z_max - 1));
	sum_v.y = -grid->y_max;
	sum_v.z = grid->z_max + (grid->x_max - 1);
	size = translate(create_coord(0,0),sum_v, dis->v_norm);
	if (size.x <= WIN_W_M && size.y <= WIN_H_M)
		return (size);
	while (size.x > WIN_W_M)
	{
		dis->v_norm = mul_vector(dis->v_norm, create_vector(0.8, 0.85, 0.8));
		size = translate(create_coord(0,0),sum_v, dis->v_norm);
	}
	return (create_coord(WIN_W_M, WIN_H_M));
}