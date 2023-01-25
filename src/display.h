/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/25 02:27:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "grid.h"
# include "display.h"
# include "matrice.h"
# define WIN_W_M 1280
# define WIN_H_M 720
# define B_X 7
# define B_Y 20
# define B_Z 14
# define ANGLE M_PI/2

typedef void	*t_mlx;
typedef void	*t_window;
typedef void	*t_img;

typedef struct s_img_data
{
	t_img	img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img_data;

typedef struct s_display

{
	t_mlx		mlx;
	t_coord		win;
	t_window	window;
	t_img_data	*img;
}	t_display;


/* Initiate t_display with everything linked to the current display*/
/* Return NULL if anything failed                                  */
t_display	*init_graph(char *title, t_grid * grid);
double	draw_line(t_display *display, t_coord start, t_coord end);
double	draw_direction(t_display *display, t_coord *start, t_vector direction);
double	draw_grid(t_display *display, t_grid *grid);
double	draw_grid2(t_display *dis, t_grid *grid, t_vector count, t_coord *c);
t_coord	size_of_grid(t_grid *grid, t_display *dis);
void	pixel_put_img(t_img_data *img, int x, int y, int color);
int		height_color(t_grid *grid, int y);

#endif