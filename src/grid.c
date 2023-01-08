/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:41:00 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/06 18:18:55 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

t_grid  *create_grid(char *fname)
{
    int y;
    t_grid  *grid;
    char    *line;
    int     *line_int;
    int     fd;

    grid = malloc(sizeof(t_grid));
    if (!grid)
        return (NULL);
    fd = open(fname, O_RDWR);
    grid->y_max = count_lines(fd);
    close(fd);
    grid->grid = malloc(sizeof(int *) * grid->y_max);
    if (!grid->grid)
        return (free(grid), NULL);
    y = 0;
    fd = open(fname, O_RDWR);
    while (y < grid->y_max)
    {
        line = get_next_line(fd);
        if (!line)
            return (free_grid(grid, y), NULL);
        grid->grid[y] = strtoi(line, &grid->x_max);
        if (!grid->grid[y])
            return (free_grid(grid, y), NULL);
        free(line);
        y++;
    }
    line = get_next_line(fd);
    return (grid);
}
void    free_grid(t_grid *grid, int y)
{
    int i;

    i = 0;
    while (i < y)
    {
        free(grid->grid[i]);
        i++;
    }
    free(grid);
}
