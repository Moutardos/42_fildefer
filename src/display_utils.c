/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:42:49 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/17 19:11:42 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

t_coord	size_of_grid(t_grid *grid, t_display *dis)
{
	t_vector	sum_v;
	t_coord		size;

	sum_v.x = -((grid->x_max - 1) + (grid->z_max - 1));
	sum_v.y = -grid->y_max;
	sum_v.z = grid->z_max + (grid->x_max - 1);
	size = translate(create_coord(0,0),sum_v, dis->v_norm);
	if (size.x <= WIN_W_M && size.y <= WIN_H_M)
		return (size);
	while (size.x > WIN_W_M)
	{
		dis->v_norm = mul_vector(dis->v_norm, create_vector(0.8, 0.85, 0.8));
		size = translate(create_coord(0,0),sum_v, dis->v_norm);
	}
	return (create_coord(WIN_W_M, WIN_H_M));
}