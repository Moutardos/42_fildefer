/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/30 09:28:03 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

double	draw_grid(t_display *dis, t_gridinfo *grid)
{
	int		i;
	int		j;
	t_coord start;
	t_coord	end;
	j = 0;
	while (j < grid->y_max - 1)
	{
		i = 0;
		while(i < grid->x_max - 1)
		{
			start = grid->grid[j][i];
			end = grid->grid[j + 1][i];
			draw_line(dis, start, grid->grid[j + 1][i]);
			draw_line(dis, start, grid->grid[j][i + 1]);
			i++;
		}
		j++;
	}
}

int	h_color(float delta, int c1, int c2)
{
	return (c1 + (delta * (c2 - c1)));
}