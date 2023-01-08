/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:27:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/06 18:22:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include <fcntl.h>
# include "../lib/libft/libft.h"

typedef struct s_grid
{
    int **grid;
    int x_max;
    int y_max;
} t_grid;

t_grid  *create_grid(char *fname);
void    free_grid(t_grid *grid, int y);
void	print_grid(t_grid * grid);
int     *strtoi(const char * str, int *len);
#endif