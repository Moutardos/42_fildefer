/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:47:05 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/12 15:41:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	render_img(t_env *env)
{
	t_gridinfo		*grid;
	t_display		*dis;
	t_matrice const	proj = MAT_PROJ;
	t_modif			*user;

	user = env->user;
	dis = env->dis;
	dis->img = new_image(env->dis);
	if (!dis->img)
		return (free(user), -1);
	grid = gridcpy(env->grid);
	if (!grid)
		return (free(user), free(dis->img), -1);
	scale_g(grid, create_coord(1, 1, user->zoom.z));
	rotate_3d(grid, user->angle.x, user->angle.y, user->angle.z);
	scale_g(grid, create_coord(user->zoom.x, user->zoom.y, 1));
	translate_g(grid, create_coord(user->move.x, user->move.y, user->move.z));
	project_g(grid, proj);
	draw_grid(dis, grid);
	free_grid(grid, grid->y_max);
	mlx_put_image_to_window(dis->mlx, dis->window, dis->img->img, 0, 0);
	return (0);
}

t_modif	*init_user(void)
{
	t_modif	*new;

	new = malloc(sizeof(t_modif));
	if (!new)
		return (NULL);
	new->angle = create_coord(A_ISO_X, A_ISO_Y, A_ISO_Z);
	new->move = create_coord(X, Y, 0);
	new->zoom = create_coord(W, H, 0.25);
	return (new);
}

t_env	*init_env(char *name)
{
	t_env		*env;
	t_gridinfo	*grid;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->grid = create_grid(name);
	if (!env->grid)
		return (free(env), NULL);
	grid = env->grid;
	env->dis = init_graph(name, grid);
	if (!env->dis)
	{
		free_grid(grid, grid->y_max);
		return (free(env), NULL);
	}
	env->user = init_user();
	if (!env->user)
	{
		free_grid(grid, grid->y_max);
		return (free_display(env->dis), free(env), NULL);
	}
	return (env);
}

void	quit_fdf(t_env *env)
{
	free_display(env->dis);
	free_grid(env->grid, env->grid->y_max);
	free(env->user);
	free(env);
	exit(0);
}

int	fdf_loop(t_env *env)
{
	mlx_key_hook(env->dis->window, key_handler, env);
	mlx_loop_hook(env->dis->mlx, render_img, env);
	mlx_loop(env->dis->mlx);
	return (0);
}
