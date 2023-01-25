/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:41:00 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 15:21:37 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

t_gridinfo	*create_grid(char *fname)
{
	t_gridinfo	*grid;
	int			fd;
	char		*line;

	grid = malloc(sizeof(t_gridinfo));
	if (!grid)
		return (NULL);
	fd = open(fname, O_RDWR);
	if (fd == -1)
		return (free(grid), NULL);
	grid->z_max = count_lines(fd);
	close(fd);
	fd = open(fname, O_RDWR);
	if (fd == -1)
		return (free(grid), NULL);
	grid->grid = malloc(sizeof(t_coord *) * grid->z_max);
	if (!grid->grid)
		return (free(grid), NULL);
	grid->x_max = -1;
	return (fill_grid(fd, grid));
}

t_grid	*fill_grid(int fd, t_gridinfo *grid)
{
	int		y;
	char	*line;
	char	**heights;
	int		i;
	t_coord	*c_line;

	y = 0;
	while (y < grid->z_max)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free_grid(grid, y), NULL);
		heights = ft_split(line, ' ');
		free(line);
		if (!heights)
			return (close(fd), free_grid(grid, y), NULL);
		c_line = fill_coord(heights, y, &grid->x_max);
		free(heights);
		if (!c_line)
			return (close(fd), free_grid(grid, y), NULL);
		grid->grid[y] = c_line;
		y++;
	}
	line = get_next_line(fd);
	close(fd);
	return (grid);
}

t_coord	*fill_coord(char **line, int y, int *x_max)
{
	int		x;
	t_coord	*points;

	x = 0;
	if (*x_max == -1)
	{
		while (*line[x])
			x++;
		*x_max = x;
		x = 0;
	}
	points = malloc(sizeof(t_coord) * x);
	if (!points)
		return (NULL);
	while(*line[x])
	{
		points[x].x = x;
		points[x].z = y;
		points[x].y = ft_atoi(line[y][x]);
		x++;
	}
	return (points);
}

void	free_grid(t_grid *grid, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid);
}
