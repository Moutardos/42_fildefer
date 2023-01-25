/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:27:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 17:34:37 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include <fcntl.h>
# include "libft/libft.h"
# include "matrice.h"

typedef t_coord** t_grid;
typedef struct s_gridinfo
{
	t_grid	grid;
	int	x_max;
	int	y_max;
}	t_gridinfo;

/** CREATION GRID **/
t_gridinfo	*create_grid(char *fname);
t_gridinfo	*fill_grid(int fd, t_gridinfo *grid);
t_coord	*fill_coord(char **line, int y, t_gridinfo *grid);
void	free_grid(t_gridinfo *grid, int y);

/** TRANSFORMATION **/
void	scale_g(t_gridinfo *grid, float scale);
void	rotate_g(t_gridinfo *grid, float rota, float rotb);
void	translate_g(t_gridinfo *grid, t_coord coord);
void	scale_height_g(t_gridinfo *grid, float scale);
void	projection_g(t_gridinfo *grid, t_matrice);
/** UTILITY **/
int		*strtoi(const char *str, int *len);
void	print_grid(t_gridinfo *grid);
int	get_max(int *arr, int len);

#endif