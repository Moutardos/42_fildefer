/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/16 16:47:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# define LINE_LEN(XA, YA, XB, YB)  sqrt(pow((XB - XA), 2) + pow((YB - YA), 2))
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;

}   t_vector;

typedef struct s_coord
{
	double	x;
	double	y;

}   t_coord;


t_vector    create_vector(double x, double y, double z);
t_coord		create_coord(double x, double y);
t_vector	mul_vector(t_vector v1, t_vector v2);
t_vector	add_vector(t_vector v1, t_vector v2);
t_coord		translate(t_coord repaire, t_vector v1, t_vector size);
#endif