/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/17 13:04:40 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "../lib/libft/libft.h"
# include "mlx.h"
# include "grid.h"
# include "vector.h"

# define WIN_W_M 1280
# define WIN_H_M 720
# define B_X 7
# define B_Y 10
# define B_Z 10
typedef void	*t_mlx;
typedef void	*t_window;

typedef struct s_display
{
	t_mlx		*mlx;
	t_coord		win;
	t_vector	v_norm;
	t_window	*window;
}	t_display;

/* Initiate t_display with everything linked to the current display*/
/* Return NULL if anything failed                                  */
t_display	*init_graph(char *title, t_grid * grid);
double	draw_line(t_display *display, t_coord start, t_coord end);
double	draw_direction(t_display *display, t_coord *start, t_vector direction);
double	draw_grid(t_display *display, t_grid *grid);
double	draw_grid2(t_display *dis, t_grid *grid, t_vector count, t_coord *c);
t_coord	size_of_grid(t_grid *grid, t_display *dis);
#endif