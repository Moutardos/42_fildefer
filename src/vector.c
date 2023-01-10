/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/09 22:21:24 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	create_vector(int x, int y, int z)
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

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	new;
	
	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}