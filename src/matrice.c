/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/28 21:29:05 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrice.h"

t_coord	create_coord(float x, float y, float z)
{
	t_coord	new;
	
	new.x = x;
	new.y = y;
	new.z = z;
	
	return new;
}

t_coord	mul_matcoord(t_coord point, t_matrice mat)
{
	t_coord	result;

	result.x = mat[0][0] * point.x + mat[0][1] * point.y + mat[0][2] * point.z;
	result.y = mat[1][0] * point.x + mat[1][1] * point.y + mat[1][2] * point.z;
	result.z = mat[2][0] * point.x + mat[2][1] * point.y + mat[2][2] * point.z;
	return (result);
}

