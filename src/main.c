/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/24 17:43:54 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "grid.h"
#include "vector.h"

int main(int argc, char const **av)
{

	t_grid *grid = create_grid(av[1]);
	if (!grid)
		printf("FAIL");
	else
	{
	t_display *dis= init_graph("test", grid);
	draw_grid(dis, grid);
	mlx_put_image_to_window(dis->mlx, dis->window, dis->img->img, 0, 0);
	mlx_loop(dis->mlx);
	free_grid(grid, grid->z_max);
	}
	return 0;
}

