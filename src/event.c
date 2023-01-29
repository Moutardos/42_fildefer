/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:47:05 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/29 17:07:17 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
int render_img(t_env *env)
{
        t_gridinfo *grid;
        t_display *dis;
        t_matrice const proj = MAT_PROJ;
        static float angle = 0;
        
        dis = env->dis;
    	grid = gridcpy(env->grid);
		dis->img = new_image(env->dis);
		if (!dis->img)
		{
			free_grid(grid, grid->y_max);
		}
		rotate_3d(grid, (ANG_ISO_A), (ANG_ISO_B - angle), 0);
		rotate_3d(grid, 0, 0, M_PI_4);
		scale_g(grid, create_coord(WIN_W*(6.0/8.0), WIN_H*(6.0/8.0), 1));
		translate_g(grid, create_coord((1.0/8.0)*WIN_W, (1.0/8.0)*WIN_H, 0));
		project_g(grid, proj);
		draw_grid(dis, grid);
		mlx_put_image_to_window(dis->mlx, dis->window, dis->img->img, 0, 0);
		angle += 0.1;
        sleep(1);
}