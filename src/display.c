/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/10 00:15:24 by lcozdenm         ###   ########.fr       */
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

double	draw_line(t_display *display, t_vector start, t_vector end)
{
	int			l_size;
	t_vector	delta;

	delta.x = end.x - start.x;
	delta.z = end.y + end.z - start.z;
	l_size = sqrt(delta.x * delta.x + delta.z * delta.z);
	delta.x /= l_size;
	delta.z /= l_size;
	while (l_size && (start.x <= end.x) && (start.z <= end.z + end.y))
	{
		printf("%d, %d\n", start.z, start.y);
		mlx_pixel_put(display->mlx, display->window, start.x, start.z, 0x336633);
		start.x += delta.x;
		start.z += delta.z;
	}
	return (l_size);
}

double	draw_direction(t_display *display, t_vector start, t_vector direction)
{
	t_vector	destination;

	destination = add_vector(start, mul_vector(V_BASE, direction));
	draw_line(display, start, destination);
}

double	draw_grid(t_display *display, t_grid *grid)
{
	t_vector	count;
	t_vector	start;
	t_vector	current;
	t_vector	decalage;
	t_vector	direction;

	start = create_vector(WIN_W/2, WIN_H/2, WIN_H/2);
	decalage = mul_vector(V_NEG, mul_vector(V_BASE, create_vector(grid->x_max, grid->z_max, grid->z_max)));
	start = add_vector(start, decalage);
	count = V_EMPTY;
	current = start;
	while (count.z < grid->z_max - 1)
	{
		while(count.x < grid->x_max)
		{
			if (count.x > 0)
			{
				direction = create_vector(0,grid->grid[count.z][count.x], 0);
				direction = add_vector(direction, add_vector(V_RIGHT, V_DOWN));
				draw_direction(display, current, direction);
			}
			if (count.x < grid->x_max - 1)
			{
				direction = create_vector(0,grid->grid[count.z][count.x], 0);
				direction = add_vector(direction, add_vector(V_RIGHT, V_UP));
				draw_direction(display, current, direction);
				current = add_vector(current, mul_vector(V_BASE, direction));
			}
			count.x++;
		}
		count = add_vector(mul_vector(count, V_FORWARD), V_FORWARD);
		current = mul_vector(V_BASE, count);
		current = add_vector(current, mul_vector(add_vector(V_DOWN, V_RIGHT), start));
	}
}

