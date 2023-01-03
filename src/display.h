/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/03 16:33:30 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "../lib/libft/libft.h"
# include "mlx.h"

# define WIN_W 1280
# define WIN_H 720

typedef void	*t_mlx;
typedef void	*t_window;

typedef struct s_display
{
	t_mlx		*mlx;
	t_window	*window;
} t_display;

/* Initiate t_display with everything linked to the current display*/
/* Return NULL if anything failed                                  */
t_display	*init_graph(char * title);
#endif