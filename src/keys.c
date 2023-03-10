/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:49:00 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/13 14:50:51 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static int	key_handler2(int key, t_env *env);

int	key_handler(int key, void *param)
{
	t_env	*env;

	env = (t_env *) param;
	if (key == 97)
		env->user->angle.y += 0.05;
	else if (key == 100)
		env->user->angle.y -= 0.05;
	else if (key == 113)
		env->user->angle.z -= 0.05;
	else if (key == 101)
		env->user->angle.z += 0.05;
	else if (key == 50)
	{
		env->user->zoom.x *= 1.05;
		env->user->zoom.y *= 1.05;
	}
	else if (key == 49)
	{
		env->user->zoom.x /= 1.05;
		env->user->zoom.y /= 1.05;
	}
	else
		return (key_handler2(key, env));
	return (0);
}

static int	key_handler2(int key, t_env *env)
{
	t_modif	*user;

	user = env->user;
	if (key == 65363)
		user->move.x -= user->zoom.y / 100;
	else if (key == 65364)
		user->move.y -= user->zoom.y / 100;
	else if (key == 65361)
		user->move.x += user->zoom.y / 100;
	else if (key == 65362)
		user->move.y += user->zoom.x / 100;
	else if (key == 61)
	{
		if (user->zoom.z < 10)
			user->zoom.z *= 1.25;
	}
	else if (key == 45)
		user->zoom.z /= 1.25;
	else if (key == 65307)
	{
		quit_fdf(env);
		return (1);
	}
	return (0);
}
