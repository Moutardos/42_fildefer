/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/28 21:12:43 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

double	draw_grid(t_display *display, t_gridinfo *grid)
{
	int		i;
	int		j;
	t_coord start;

	j = 0;
	while (j < grid->y_max - 1)
	{
		i = 0;
		while(i < grid->x_max - 1)
		{
			start = grid->grid[j][i];
				draw_line(display, start, grid->grid[j + 1][i], 0xffffff);
				draw_line(display, start, grid->grid[j][i + 1], 0xffffff);
			i++;
		}
		j++;
	}
}
