/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 15:09:35 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

double	draw_direction(t_display *display, t_coord *start, t_vector direction)
{
	t_coord	destination;

	destination = translate(*start, direction, display->v_norm);
	draw_line(display, *start, destination);
	*start = destination;
}


double	draw_grid(t_display *display, t_grid *grid, t_coord start)
{
	t_coord	cursor;
	t_coord	decalage;

	start = translate(start, decalage, display->v_norm);
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
