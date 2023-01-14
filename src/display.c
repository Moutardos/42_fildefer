/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/14 13:45:23 by lcozdenm         ###   ########.fr       */
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

	new->window = mlx_new_window(new->mlx, WIN_W, WIN_H, title);
	if (!new->window)
		return (free(new->mlx), free(new), NULL);
	return (new);
}

double	draw_line(t_display *display, t_coord start, t_coord end)
{
	double		l_size;
	t_coord		delta;

	l_size = LINE_LEN(start.x, start.y, end.x, end.y);
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

	destination = translate(*start, direction, V_BASE);
	draw_line(display, *start, destination);
	*start = destination;
}


double	draw_grid(t_display *display, t_grid *grid)
{
	t_vector	count;
	t_coord		start;
	t_coord		cursor;
	t_vector	decalage;

	start = create_coord(WIN_W/2, WIN_H/2);
	decalage = create_vector(grid->x_max, grid->y_max, -grid->z_max);
	start = translate(start, decalage, V_BASE);
	count = V_EMPTY; 
	cursor = start;
	while (count.z < grid->z_max - 1)
	{
		while(count.x < grid->x_max)
		{
			draw_grid2(display, grid, count, &cursor);
			count.x++;
		}
		count.x = 0;
		count.z++;
		decalage = create_vector(count.z,grid->grid[(int)count.z][0],count.z);
		cursor = translate(start, decalage, V_BASE);
	}
}

double	draw_grid2(t_display *dis, t_grid *grid, t_vector count, t_coord *c)
{
	t_vector	direction;

	if (count.x > 0)
	{
		direction = V_EMPTY;
		direction = add_vector(direction, add_vector(V_LEFT, V_FORWARD));
		direction.y -= grid->grid[(int) count.z][(int) count.x];
		direction.y += grid->grid[(int) count.z +1][(int) count.x];
		draw_direction(dis, c, direction);
		*c = translate(*c, mul_vector(V_NEG, direction), V_BASE);
	}
	if (count.x < grid->x_max - 1)
	{
		direction = V_EMPTY;
		direction = add_vector(V_RIGHT, V_FORWARD);
		direction.y -= grid->grid[(int) count.z][(int) count.x];
		direction.y += grid->grid[(int) count.z][(int) count.x + 1];
		draw_direction(dis, c, direction);
	}
}
