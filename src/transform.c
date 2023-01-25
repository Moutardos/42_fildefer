/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 17:43:47 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	scale_g(t_gridinfo *grid, float scale)
{
	int j;
	int i;
	t_coord *point;

	j = 0;
	while (j < grid->y_max)
	{
		i = 0;
		while (i < grid->x_max)
	   {
			point = &grid->grid[j][i];
			point->x *= scale;
			point->y *= scale;
			point->z *= scale;
			i++;
		}
		j++;
	}
}

void	rotate_g(t_gridinfo *grid, float rota, float rotb)
{
	int j;
	int i;
	t_coord *point;
	t_matrice mat_rota;
	t_matrice mat_rotb;


	mat_rota = {{1, 0, 0},{0, cos(rota), sin(rota)},{0, -sin(rota), cos(rota)}};
	mat_rotb = {{cos(rotb), 0, -sin(rotb)},{0, 1, 0},{sin(rotb), 0, cos(rotb)}};
	j = 0;
	while (j < grid->y_max)
	{
		i = 0;
		while (i < grid->x_max)
	   {
			point = &grid->grid[j][i];
			point = mul_matcoord(point, mat_rota);
			point = mul_matcoord(point, mat_rotb);
		}
		j++;
	} 
}

void	translate_g(t_gridinfo *grid, t_coord coord);
void	scale_height_g(t_gridinfo *grid, float scale);
