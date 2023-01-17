/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/17 13:00:30 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	create_vector(double x, double y, double z)
{
	t_vector	new;
	
	new.x = x;
	new.y = y;
	new.z = z;
	
	return new;
}

t_vector	mul_vector(t_vector v1, t_vector v2)
{
	t_vector	new;
	
	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}


t_coord	create_coord(double x, double y)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	return new;
}
t_coord	translate(t_coord repaire, t_vector v1, t_vector size)
{
	t_coord new;

	new.x	= repaire.x + (v1.z * size.z);
	new.y	= repaire.y - (v1.x * size.x) - (v1.y * size.y);
	return (new);
}