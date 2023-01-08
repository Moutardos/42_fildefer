/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/06 18:26:40 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "grid.h"
int main(int argc, char const **av)
{
	char	*fname;

	fname = ft_strjoin("maps/",av[1]);
	t_grid *grid = create_grid(fname);
	if (!grid)
		printf("FAIL");
	else
	{
		print_grid(grid);
	}
	free(fname);
	free_grid(grid, grid->y_max);
	/*	t_display *dis= init_graph("test");
	mlx_string_put(dis->mlx, dis->window, WIN_W/2, WIN_H/2, 0x336633,"coucou");
	mlx_loop(dis->mlx);*/
	return 0;
}

