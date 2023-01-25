/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 01:37:25 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# define _USE_MATH_DEFINES
# define LINE_LEN(XA, YA, XB, YB)  sqrt(pow((XB - XA), 2) + pow((YB - YA), 2))

typedef float	t_matrice[4][4];

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}   t_coord;

t_coord	create_coord(double x, double y, double z);
t_coord	mul_matcoord(t_coord point, t_matrice mat);


#endif