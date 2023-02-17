/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 09:23:20 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include <math.h>
# define _USE_MATH_DEFINES

/* Matrix 3x3 */
typedef float	t_matrice[3][3];

/* Coordinate in a 3 dimensional plane */
typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

/* Return a coordinate x,y,z */
t_coord	create_coord(float x, float y, float z);

/* Multiply a 3x3 matrice to a 3x1 one and return the result*/
t_coord	mul_matcoord(t_coord point, const t_matrice mat);

#endif