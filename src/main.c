/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/29 16:57:07 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "display.h"
#include "event.h"
int main(int argc, char **av)
{
	float angle = 0;
	t_gridinfo		*grid;
	t_gridinfo		*original = create_grid(av[1]);
	t_env			*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);	
	if (!original)
		printf("FAIL");
	else
	{
		t_display *dis= init_graph("test", original);
		if (!dis)
			return (0);
		env->dis = dis;
		env->grid = original;
		mlx_loop_hook(dis->mlx, render_img, env);
		mlx_loop(dis->mlx);
	}
	// draw_grid(dis, grid);
	return 0;
}
