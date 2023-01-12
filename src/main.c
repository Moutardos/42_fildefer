/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/12 05:44:14 by lcozdenm         ###   ########.fr       */
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
	t_grid *grid = create_grid(av[1]);
	if (!grid)
		printf("FAIL");
	else
	{
		print_grid(grid);
			t_display *dis= init_graph("test", grid);
	draw_grid(dis, grid);
	mlx_loop(dis->mlx);
		free_grid(grid, grid->z_max);
	}
	free(fname);
	return 0;
}

