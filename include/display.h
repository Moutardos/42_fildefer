/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 09:53:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "grid.h"
# include "display.h"
# include "matrice.h"
# define WIN_W 2560
# define WIN_H 1400
// Isometric view
# define A_ISO_X 3.390000
# define A_ISO_Y 2.918592
# define A_ISO_Z -3.934515
// 6/8 of WIN_W
# define W 1920
// 6/8 of WIN_H
# define H 1050
// 1/8 of WIN_W
# define X 320
// 1/8 of WIN_H
# define Y 175

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
	t_window	window;
	t_img_data	*img;
	int			c1;
	int			c2;
}	t_display;

/* 
*  Initiate t_display with everything linked to the current display
*  Return NULL if anything failed
*/
t_display	*init_graph(char *title);

/* 
*  Draw a line from start to end in the img given by display 
*  Return the number of pixels drawn
*/
double		draw_line(t_display *display, t_coord start, t_coord end);

/* Draw the grid in the img given by display */
void		draw_grid(t_display *dis, t_gridinfo *grid);

/* Put a pixel of a given color in the image */
void		pixel_put_img(t_img_data *img, int x, int y, int color);

/* Return the color depending on the delta from c1 to c2 */
int			h_color(float delta, int c1, int c2);

/* Allocate and return a new image */
t_img_data	*new_image(t_display *dis);

/* Free the different ressources in display */
void		free_display(t_display *dis);
#endif
