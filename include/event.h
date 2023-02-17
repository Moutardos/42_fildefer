/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:46:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 09:57:46 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include "display.h"
# include "grid.h"

# define EXIT_BUTTON 17
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L)

/* The modifier given by the user */
typedef struct s_modif
{
	t_coord	zoom;
	t_coord	move;
	t_coord	angle;
}	t_modif;

/* Storing all the data used by hooks*/
typedef struct s_env
{
	t_display	*dis;
	t_gridinfo	*grid;
	t_modif		*user;
}	t_env;

/* Do differents action depending on the key pressed by the user 
* AD : move the grid on the X axis
* QE : move the grid on the Z axis
* 21 : zoom in/out
* -+ : zoom the Z axis  
* arrow keys : move the grid
*/
int		key_handler(int key, void *param);

/* Initiate the struct modifier */
t_modif	*init_user(void);

/* Initiate the struct environement */
t_env	*init_env(char *name);
/* Render the grid by taking a copy of the original one, 
*  rotating, scaling and translating it before projecting on the 2d plan.
*  Use the different modifier in the struct modifier to do so.
*/
int		render_img(t_env *env);

/* Apply the differents hooks before looping the render_img*/
int		fdf_loop(t_env *env);

/* Free the environement and quit the program */
int		quit_fdf(t_env *env);

#endif