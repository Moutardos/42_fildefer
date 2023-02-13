/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/13 13:08:00 by lcozdenm         ###   ########.fr       */
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

/* Initiate t_display with everything linked to the current display*/
/* Return NULL if anything failed                                  */
t_display	*init_graph(char *title);
double		draw_line(t_display *display, t_coord start, t_coord end);
void		draw_grid(t_display *dis, t_gridinfo *grid);
// t_coord	size_of_grid(t_grid *grid, t_display *dis);
void		pixel_put_img(t_img_data *img, int x, int y, int color);
int			h_color(float delta, int c1, int c2);
t_img_data	*new_image(t_display *dis);
void		free_display(t_display *dis);
#endif
