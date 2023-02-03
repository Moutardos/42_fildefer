/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/03 20:15:50 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "display.h"
#include "event.h"
int main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	{
		ft_printf("bin/fdf PATH_TO_FDF_FILE\n");
		return (0);
	}
	env = init_env(av[1]);
	if (!env)
	{
		ft_printf("Couldn't read the fdf file\n");
		return (0);
	}
	// ft_printf("Welcome!\nUse the directional keys to move around\n");
	// ft_printf("AD for rotating on the x-axis and QE for the  z one.");
	// ft_printf("\n1 to zoom, 2 to unzoom\n+ and - to change the height\n");
	fdf_loop(env);
	return (0);
}
