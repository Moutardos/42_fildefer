/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:46:54 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/29 16:57:43 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "grid.h"

typedef struct s_env
{
    t_display	*dis;
    t_gridinfo	*grid;
}	t_env;

int render_img(t_env *env);