/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:27:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 03:03:31 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "matrice.h"

typedef t_coord** t_grid;
typedef struct s_gridinfo
{
	t_grid	grid;
	int	x_max;
	int	z_max;
}	t_gridinfo;

t_grid	*create_grid(char *fname);
t_grid	*fill_grid(int fd, t_gridinfo *grid);
void	free_grid(t_gridinfo *grid, int y);
void	print_grid(t_gridinfo *grid);
int		*strtoi(const char *str, int *len);
int	get_max(int *arr, int len);
#endif