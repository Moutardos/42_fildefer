/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/30 14:37:30 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "display.h"
#include "event.h"
int main(int ac, char **av)
{
	t_env			*env;
	
	if (ac != 2)
	{
		ft_printf("Veuillez fournir le chemin de la map comme argument\n");
		return (0);
	}
	env = init_env(av[1]);
	if (!env)
	{
		ft_printf("Erreur lors de la lecture du fichier :(\n");
		return (0);
	}
	mlx_key_hook(env->dis->window, key_handler, env->user);
	mlx_loop_hook(env->dis->mlx, render_img, env);
	mlx_loop(env->dis->mlx);
	return (0);
}
