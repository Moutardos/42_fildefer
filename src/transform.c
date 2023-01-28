/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/28 21:43:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	scale_g(t_gridinfo *grid, t_coord scale)
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
			point->x *= scale.x;
			point->y *= scale.y;
			point->z *= scale.z;
			i++;
		}
		j++;
	}
}


void	translate_g(t_gridinfo *grid, t_coord coord)
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
			point->x += coord.x;
			point->y += coord.y;
			point->z += coord.z;
			i++;
		}
		j++;
	}

}

void	project_g(t_gridinfo *grid, t_matrice mat)
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
			*point = mul_matcoord(*point, mat);
			i++;
		}
		j++;
	}
}

void	rotate_3d(t_gridinfo *grid, float x, float y, float z)
{
	int j;
	int i;
	t_coord *point;
	const t_matrice mat_x = {{1, 0, 0},{0, cos(x), sin(x)},{0, -sin(x), cos(x)}};
	const t_matrice mat_y = {{cos(y), 0, -sin(y)},{0, 1, 0},{sin(y), 0, cos(y)}};
	const t_matrice mat_z = {{cos(z), sin(z), 0},{-sin(z), cos(z), 0},{0, 0, 1}};

	j = 0;
	while (j < grid->y_max)
	{
		i = 0;
		while (i < grid->x_max)
	   {
			point = &grid->grid[j][i];
			*point = mul_matcoord(*point, mat_x);
			*point = mul_matcoord(*point, mat_y);
			*point = mul_matcoord(*point, mat_z);
			i++;
		}
		j++;
	}
}