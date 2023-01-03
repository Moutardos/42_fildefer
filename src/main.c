/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/03 16:38:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int main(int argc, char const **argv)
{
	t_display *dis= init_graph("test");
	mlx_string_put(dis->mlx, dis->window, WIN_W/2, WIN_H/2, 0x336633,"coucou");
	mlx_loop(dis->mlx);
	return 0;
}

