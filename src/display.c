/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/03 15:20:31 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

t_display	*init_graph(char * title)
{
	t_display	*new;

	if (title == NULL)
		return (NULL);
	new = malloc(sizeof(t_display));
	if (!new)
		return (NULL);
	new->mlx = mlx_init();
	if (!new->mlx)
		return (free(new), NULL);
	new->window = mlx_new_window(new->mlx, WIN_W, WIN_H, title);
	if (!new->window)
		return (free(new->mlx),free(new), NULL);
	return (new);
}

