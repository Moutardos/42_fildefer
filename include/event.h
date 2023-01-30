/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:46:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/30 14:40:36 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "grid.h"

typedef struct	s_modif
{
	t_coord	zoom;
	t_coord	move;
	t_coord	angle;
}	t_modif;

typedef struct	s_env
{
	t_display	*dis;
	t_gridinfo	*grid;
	t_modif		*user;
}	t_env;



int     render_img(t_env *env);
int     key_handler2(int key, t_modif *user);
int     key_handler(int key, void *user);
t_modif	*init_user(void);
t_env	*init_env(char *name);