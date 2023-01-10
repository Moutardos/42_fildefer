/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/10 00:16:47 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "grid.h"
#include "vector.h"
int main(int argc, char const **av)
{
	char	*fname;
	t_vector	start;
	t_vector	end;

	start.x = WIN_W/2 - 50;
	end.x	= WIN_W/2 + 50;
	start.z = WIN_H/2 - 50;
	end.z = WIN_H/2 - 50;
	start.y = 0;
	end.y = 0;
	fname = ft_strjoin("maps/",av[1]);
	t_grid *grid = create_grid(fname);
	if (!grid)
		printf("FAIL");
	else
	{
		print_grid(grid);
	}
	free(fname);
	t_display *dis= init_graph("test", grid);
	draw_direction(dis, start, create_vector(1,0,-1));
	mlx_loop(dis->mlx);
		free_grid(grid, grid->z_max);
	return 0;
}

