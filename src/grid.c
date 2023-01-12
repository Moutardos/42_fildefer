/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:41:00 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/12 06:06:56 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

t_grid	*create_grid(char *fname)
{
	t_grid	*grid;
	int		fd;
	char	*line;
	grid = malloc(sizeof(t_grid));
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
	grid->grid = malloc(sizeof(int *) * grid->z_max);
	if (!grid->grid)
		return (free(grid), NULL);
	return (fill_grid(fd, grid));
}

t_grid	*fill_grid(int fd, t_grid *grid)
{
	int		y;
	char	*line;

	y = 0;
	while (y < grid->z_max)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free_grid(grid, y), NULL);
		grid->grid[y] = strtoi(line, &grid->x_max);
		if (!grid->grid[y])
			return (close(fd), free_grid(grid, y), NULL);
		free(line);
		y++;
	}
	line = get_next_line(fd);
	close(fd);
	return (grid);
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
