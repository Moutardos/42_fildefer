/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/12 08:55:17 by lcozdenm         ###   ########.fr       */
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
	t_coord		current;
	t_vector	decalage;
	t_vector	direction;

	start = create_coord(WIN_W/2, WIN_H/2);
	start = translate(start, create_vector(-grid->x_max/2, 0, -grid->z_max/2), V_BASE);
	count = V_EMPTY; 
	current = start;
	while (count.z < grid->z_max - 1)
	{
		while(count.x < grid->x_max)
		{
			if (count.x > 0)
			{
				direction = V_EMPTY;
				direction = add_vector(direction, add_vector(V_LEFT, V_FORWARD));
				direction.y -= grid->grid[(int) count.z][(int) count.x];
				direction.y += grid->grid[(int) count.z +1][(int) count.x - 1];
				draw_direction(display, &current, direction);
				current = translate(current, mul_vector(V_NEG, direction), V_BASE);
			}
			if (count.x < grid->x_max - 1)
			{
				direction = V_EMPTY;
				direction = add_vector(V_RIGHT, V_FORWARD);
				direction.y -= grid->grid[(int) count.z][(int) count.x];
				direction.y += grid->grid[(int) count.z][(int) count.x + 1];
				draw_direction(display, &current, direction);
			}
			count.x++;
		}
		count = add_vector(mul_vector(count, V_FORWARD), V_FORWARD);
		current = translate(start, create_vector(count.z,grid->grid[(int)count.z][0],count.z), V_BASE);
	}
}

