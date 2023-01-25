/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 17:39:05 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "display.h"
#include "grid.h"
#include "display.h"

int main(int argc, char **av)
{

	t_gridinfo *grid = create_grid(av[1]);
	if (!grid)
		printf("FAIL");
	else
	{
	// t_display *dis= init_graph("test", grid);
	// draw_grid(dis, grid);
	// mlx_put_image_to_window(dis->mlx, dis->window, dis->img->img, 0, 0);
	// mlx_loop(dis->mlx);
	scale_g(grid, 100);
	rotate_g(grid, (ANG_ISO_A), (ANG_ISO_B));
	print_grid(grid);
	free_grid(grid, grid->y_max);
	}
	return 0;
}

