/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/12 05:11:46 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# define V_UP create_vector(0, -1, 0)
# define V_DOWN create_vector(0, 1, 0)
# define V_RIGHT create_vector(1, 0, 0)
# define V_LEFT create_vector(-1, 0, 0)
# define V_FORWARD create_vector(0, 0, 1)
# define V_BACK create_vector(0, 0, -1)
# define V_NORMAL create_vector(1, 1 ,1)
# define V_NEG create_vector(1, 1 ,1)
# define V_EMPTY create_vector(0, 0, 0)

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;

}   t_vector;


t_vector    create_vector(double x, double y, double z);
t_vector	mul_vector(t_vector v1, t_vector v2);
t_vector	add_vector(t_vector v1, t_vector v2);
#endif