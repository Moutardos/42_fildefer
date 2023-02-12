/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/12 16:42:14 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	scale_g(t_gridinfo *grid, t_coord scale)
{
	int		j;
	int		i;
	t_coord	*point;

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
	int		j;
	int		i;
	t_coord	*point;

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
	int		j;
	int		i;
	float	z;
	t_coord	*point;

	j = 0;
	while (j < grid->y_max)
	{
		i = 0;
		while (i < grid->x_max)
		{
			point = &grid->grid[j][i];
			z = point->z;
			*point = mul_matcoord(*point, mat);
			point->z = z;
			i++;
		}
		j++;
	}
}

void	rotate_3d(t_gridinfo *grid, float x, float y, float z)
{
	int				j;
	int				i;
	const t_matrice	mx = {{1, 0, 0}, {0, cos(x), -sin(x)}, {0, sin(x), cos(x)}};
	const t_matrice	my = {{cos(y), 0, sin(y)}, {0, 1, 0}, {-sin(y), 0, cos(y)}};
	const t_matrice	mz = {{cos(z), -sin(z), 0}, {sin(z), cos(z), 0}, {0, 0, 1}};

	j = 0;
	translate_g(grid, create_coord(-0.5, -0.5, 0));
	while (j < grid->y_max)
	{
		i = 0;
		while (i < grid->x_max)
		{
			grid->grid[j][i] = mul_matcoord(grid->grid[j][i], my);
			grid->grid[j][i] = mul_matcoord(grid->grid[j][i], mx);
			grid->grid[j][i] = mul_matcoord(grid->grid[j][i], mz);
			i++;
		}
		j++;
	}
	translate_g(grid, create_coord(0.5, 0.5, 0));
}
