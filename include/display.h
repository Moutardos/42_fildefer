/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/28 21:00:53 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "libft/libft.h"
# include "mlx_mac/mlx.h"
# include "grid.h"
# include "display.h"
# include "matrice.h"
# define WIN_W 1280
# define WIN_H 720
# define ANGLE M_PI/2
# define ANG_ISO_A 0.615472907
# define ANG_ISO_B 0.785398

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
}	t_display;


/* Initiate t_display with everything linked to the current display*/
/* Return NULL if anything failed                                  */
t_display	*init_graph(char *title, t_gridinfo * grid);
double	draw_line(t_display *display, t_coord start, t_coord end, int color);
double	draw_grid(t_display *display, t_gridinfo *grid);
// t_coord	size_of_grid(t_grid *grid, t_display *dis);
void	pixel_put_img(t_img_data *img, int x, int y, int color);
// int		height_color(t_grid *grid, int y);

#endif