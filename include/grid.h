/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:27:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 09:54:58 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include <fcntl.h>
# include "libft/libft.h"
# include "matrice.h"

/* A grid is a 2 dimensional array of coordinates */
typedef t_coord**	t_grid;

/*
* `gridinfo` is a structure that contains the grid
* and the maximum values of x, y and z
*/
typedef struct s_gridinfo
{
	t_grid	grid;
	int		x_max;
	int		y_max;
	int		z_max;
}	t_gridinfo;

/* 
* A valid .fdf file must be given to the executable. A .fdf file is a grid
* of x*x coordinates. Each coordinate is separated by a space and each line
* is separated by a new line. Each coordinate is composed of 3 integers
* which is refered by the z value in the x y position of the grid.
*/

/** CREATION GRID **/
/* 
*  Create a grid of coordinates by looking at the data in the file fname, the
*  program trusts the user will give a valid .fdf file
*/
t_gridinfo	*create_grid(char *fname);

/* Fill the grid with the data from the file */
t_gridinfo	*fill_grid(int fd, t_gridinfo *grid);

/* 
* Return a line of coordinates by translating line into an array of number
* the coordinates are then used by looking at the x and y position of the 
* z value in the file. The coordinates are then divided by the maximum value
* of x, y and z to normalize the grid.
*/
t_coord		*fill_coord(char **line, int y, t_gridinfo *grid);

/* Return a allocated copy of the grid in parameter */
t_gridinfo	*gridcpy(t_gridinfo *grid);

/* Free the grid and the gridinfo structure */
void		free_grid(t_gridinfo *grid, int y);

/** TRANSFORMATION **/

/* Multiply the coordinates of the grid by the scale factor */
void		scale_g(t_gridinfo *grid, t_coord scale);

/* Translate the coordinates of the grid by the coord */
void		translate_g(t_gridinfo *grid, t_coord coord);

/* Project the grid on the x,y,z plane */
void		project_g(t_gridinfo *grid, const t_matrice mat);

/* Rotate the grid on the x,y,z axis */
void		rotate_3d(t_gridinfo *grid, float x, float y, float z);
/** UTILITY **/

/* 
* Split a string containing numbers
* and then convert them into an array of int
*/
int			*strtoi(const char *str, int *len);

/* Print the grid */
void		print_grid(t_gridinfo *grid);

/* Return the maximum value of an array of int */
int			get_max(int *arr, int len);

/* Free an array of string */
void		free_split(char **s);

#endif