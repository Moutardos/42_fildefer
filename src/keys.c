/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:49:00 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/03 19:35:37 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int key_handler(int key, void *param)
{
	t_env	*env;
	t_modif	*user;

	env = (t_env *) param;
	user = env->user;
	printf("%d\n", key);
	if (key == 97)
		user->angle.y += 0.15;
	else if (key == 100)
		user->angle.y -= 0.15;
	else if (key == 113)
		user->angle.z -= 0.15;
	else if (key == 101)
		user->angle.z += 0.15;
	else if (key == 50)
	{
		user->zoom.x *= 1.25;
		user->zoom.y *= 1.25;
	}
	else if (key == 49)
	{
		user->zoom.x /= 1.25;
		user->zoom.y /= 1.25;
	}
	else
		return (key_handler2(key, env));
	return (0);
}

int key_handler2(int key, t_env *env)
{
	t_modif	*user;

	user = env->user;
	if (key == 65363)
		user->move.x -= user->zoom.y/10;
	else if (key == 65364)
		user->move.y -= user->zoom.y/10;
	else if (key == 65361)
		user->move.x += user->zoom.y/10;
	else if (key == 65362)
		user->move.y += user->zoom.x/10;
	else if (key == 45)
	{
		if (user->zoom.z < 10)
			user->zoom.z *= 1.25;
	}
	else if (key == 61)
		user->zoom.z /= 1.25;
	else if (key == 65307)
	{
		quit_fdf(env);
		return (1);
	}
	return (0);
}