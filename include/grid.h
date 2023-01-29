/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:27:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/29 16:30:15 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include <fcntl.h>
# include "libft/libft.h"
# include "matrice.h"
# define MAT_PROJ {{1, 0, 0},{0, 1, 0},{0, 0, 0}}

typedef t_coord** t_grid;
typedef struct s_gridinfo
{
	t_grid	grid;
	int	x_max;
	int	y_max;
	int	z_max;
}	t_gridinfo;

/** CREATION GRID **/
t_gridinfo	*create_grid(char *fname);
t_gridinfo	*fill_grid(int fd, t_gridinfo *grid);
t_coord	*fill_coord(char **line, int y, t_gridinfo *grid);
t_gridinfo	*gridcpy(t_gridinfo *grid);
void	free_grid(t_gridinfo *grid, int y);

/** TRANSFORMATION **/
void	scale_g(t_gridinfo *grid, t_coord scale);
void	rotate_g(t_gridinfo *grid, float rota, float rotb);
void	translate_g(t_gridinfo *grid, t_coord coord);
void	project_g(t_gridinfo *grid, t_matrice mat);
void	rotate_3d(t_gridinfo *grid, float x, float y, float z);
/** UTILITY **/
int		*strtoi(const char *str, int *len);
void	print_grid(t_gridinfo *grid);
int	get_max(int *arr, int len);

#endif