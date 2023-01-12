/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/12 09:01:46 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "../lib/libft/libft.h"
# include "mlx.h"
# include "grid.h"
# include "vector.h"

# define WIN_W 1280
# define WIN_H 720
# define V_BASE create_vector(9, 20, 9)
typedef void	*t_mlx;
typedef void	*t_window;

typedef struct s_display
{
	t_mlx		*mlx;
	int			win_h;
	int			win_w;
	t_window	*window;
	
}	t_display;

/* Initiate t_display with everything linked to the current display*/
/* Return NULL if anything failed                                  */
t_display	*init_graph(char *title, t_grid * grid);
double	draw_line(t_display *display, t_coord start, t_coord end);
double	draw_direction(t_display *display, t_coord *start, t_vector direction);
double	draw_grid(t_display *display, t_grid *grid);
#endif