/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/13 12:12:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include <math.h>
# define _USE_MATH_DEFINES

typedef float	t_matrice[3][3];

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

t_coord	create_coord(float x, float y, float z);
t_coord	mul_matcoord(t_coord point, const t_matrice mat);

#endif