/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/28 21:58:32 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "display.h"
#include "grid.h"
#include "display.h"

int main(int argc, char **av)
{
	t_matrice const proj = MAT_PROJ;
	t_gridinfo *grid = create_grid(av[1]);
	if (!grid)
		printf("FAIL");
	else
	{
	t_display *dis= init_graph("test", grid);
	// draw_grid(dis, grid);
	translate_g(grid, create_coord(0.5, 0.5, 0));
	scale_g(grid, create_coord(WIN_W/2, WIN_H/2, 1));
	scale_g(grid, create_coord(1 , 1, 10));
	rotate_3d(grid, (ANG_ISO_A), (ANG_ISO_B), 0);
	project_g(grid, proj);
	draw_grid(dis, grid);
	mlx_put_image_to_window(dis->mlx, dis->window, dis->img->img, 0, 0);
	mlx_loop(dis->mlx);
	free_grid(grid, grid->y_max);
	}
	return 0;
}
