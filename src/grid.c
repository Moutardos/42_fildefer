/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:41:00 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 10:12:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

t_gridinfo	*create_grid(char *fname)
{
	t_gridinfo	*grid;
	int			fd;

	grid = malloc(sizeof(t_gridinfo));
	if (!grid)
		return (NULL);
	fd = open(fname, O_RDWR);
	if (fd == -1)
		return (free(grid), NULL);
	grid->y_max = count_lines(fd);
	close(fd);
	fd = open(fname, O_RDWR);
	if (fd == -1)
		return (free(grid), NULL);
	grid->grid = malloc(sizeof(t_coord *) * grid->y_max);
	if (!grid->grid)
		return (free(grid), NULL);
	grid->x_max = -1;
	grid->z_max = 1;
	grid = fill_grid(fd, grid);
	if (!grid)
		return (NULL);
	scale_g(grid, create_coord(1, 1, (1.0 / ((float)grid->z_max))));
	return (grid);
}

t_gridinfo	*fill_grid(int fd, t_gridinfo *grid)
{
	int		y;
	char	*line;
	char	**heights;
	t_coord	*c_line;

	y = 0;
	while (y < grid->y_max)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free_grid(grid, y), NULL);
		heights = ft_split(line, ' ');
		free(line);
		if (!heights)
			return (close(fd), free_grid(grid, y), NULL);
		c_line = fill_coord(heights, y, grid);
		free_split(heights);
		if (!c_line)
			return (close(fd), free_grid(grid, y), NULL);
		grid->grid[y] = c_line;
		y++;
	}
	line = get_next_line(fd);
	return (close(fd), grid);
}

t_coord	*fill_coord(char **line, int y, t_gridinfo *grid)
{
	int		x;
	t_coord	*points;

	x = 0;
	if (grid->x_max == -1)
	{
		while (line[x])
			x++;
		grid->x_max = x;
	}
	x = 0;
	points = malloc(sizeof(t_coord) * grid->x_max);
	if (!points)
		return (NULL);
	while (line[x])
	{
		if (ft_atoi(line[x]) > grid->z_max)
			grid->z_max = ft_atoi(line[x]);
		points[x].z = (float) -ft_atoi(line[x]);
		points[x].x = ((float) x) / (grid->x_max - 1);
		points[x].y = ((float) y) / (grid->y_max - 1);
		x++;
	}
	return (points);
}

t_gridinfo	*gridcpy(t_gridinfo *grid)
{
	t_gridinfo	*cpy;
	int			y;
	int			x;

	cpy = malloc(sizeof(t_gridinfo));
	if (!cpy)
		return (NULL);
	cpy->x_max = grid->x_max;
	cpy->y_max = grid->y_max;
	cpy->z_max = grid->z_max;
	cpy->grid = malloc(sizeof(t_coord *) * grid->y_max);
	if (!cpy->grid)
		return (free(cpy), NULL);
	y = 0;
	while (y < grid->y_max)
	{
		cpy->grid[y] = malloc(sizeof(t_coord) * grid->x_max);
		if (!cpy->grid[y])
			return (free_grid(cpy, y), NULL);
		x = -1;
		while (++x < grid->x_max)
			cpy->grid[y][x] = grid->grid[y][x];
		y++;
	}
	return (cpy);
}

void	free_grid(t_gridinfo *grid, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
	free(grid);
	grid = NULL;
}
