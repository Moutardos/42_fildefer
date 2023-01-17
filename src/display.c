/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/17 17:41:34 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

t_display	*init_graph(char *title, t_grid *grid)
{
	t_display	*new;

	if (title == NULL)
		return (NULL);
	new = malloc(sizeof(t_display));
	if (!new)
		return (NULL);
	new->mlx = mlx_init();
	if (!new->mlx)
		return (free(new), NULL);
	new->v_norm = create_vector(B_X, B_Y, B_Z);
	new->win = size_of_grid(grid, new);
	new->window = mlx_new_window(new->mlx, new->win.x, new->win.y, title);
	if (!new->window)
		return (free(new->mlx), free(new), NULL);
	return (new);
}

double	draw_line(t_display *display, t_coord start, t_coord end)
{
	double		l_size;
	t_coord		delta;

	l_size = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2));
	delta.x = (end.x - start.x) / l_size;
	delta.y = (end.y - start.y) / l_size;
	while (l_size > 0)
	{
		mlx_pixel_put(display->mlx, display->window, start.x, start.y, 0x336633);
		start.x += delta.x;
		start.y += delta.y;
		l_size--;
	}
	return (l_size);
}

double	draw_direction(t_display *display, t_coord *start, t_vector direction)
{
	t_coord	destination;

	destination = translate(*start, direction, display->v_norm);
	draw_line(display, *start, destination);
	*start = destination;
}


double	draw_grid(t_display *display, t_grid *grid)
{
	t_vector	count;
	t_coord		start;
	t_coord		cursor;
	t_vector	decalage;

	start = create_coord(display->win.x/2, display->win.y/2);
	decalage = create_vector((-(grid->x_max - 1)/2 + (grid->z_max - 1)/2), -(grid->y_max + 1)/2, (-grid->z_max - (grid->x_max - 1))/2);
	start = translate(start, decalage, display->v_norm);
	count = create_vector(0, 0, 0); 
	cursor = start;
	while (count.z < grid->z_max - 1)
	{
		cursor = translate(cursor, create_vector(0,grid->grid[(int) count.z][(int) count.x], 0), display->v_norm);
		while(count.x < grid->x_max)
		{
			draw_grid2(display, grid, count, &cursor);
			count.x++;
		}
		count.z++;
		count.x = 0;
		decalage = create_vector(-count.z, 0 ,count.z);
		cursor = translate(start, decalage, display->v_norm);
	}
}

double	draw_grid2(t_display *dis, t_grid *grid, t_vector count, t_coord *c)
{
	t_vector	direction;
	t_vector	v_front_left;
	t_vector	v_front_right;
	t_vector	v_neg;

	v_front_left = create_vector(-1, 0, 1);
	v_front_right = create_vector(1, 0, 1);
	v_neg = create_vector(-1, -1, -1);
	if (count.x > 0)
	{
		direction = v_front_left;
		direction.y -= grid->grid[(int) count.z][(int) count.x];
		direction.y += grid->grid[(int) count.z +1][(int) count.x];
		draw_direction(dis, c, direction);
		*c = translate(*c, mul_vector(v_neg, direction), dis->v_norm);
	}
	if (count.x < grid->x_max - 1)
	{
		direction = v_front_right;
		direction.y -= grid->grid[(int) count.z][(int) count.x];
		direction.y += grid->grid[(int) count.z][(int) count.x + 1];
		draw_direction(dis, c, direction);
	}
}
