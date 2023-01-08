/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:46:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/01/06 18:14:27 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int *strtoi(const char * str, int *x_max)
{
	char			**to_atoi;
	int				*res;
	unsigned int	len;
	unsigned int	i;
	
	to_atoi = ft_split(str, ' ');
	if (!to_atoi)
		return  (NULL);
	len = 0;
	i = 0;
	while (to_atoi[len])
		len++;
	res = malloc(sizeof(int) * len);
	while (res && i < len)
	{
		res[i] = ft_atoi(to_atoi[i]);
		i++;
	}
	i = 0;
	while (res && i < len)
	{
		free(to_atoi[i]);
		i++;
	}
	free(to_atoi);
	*x_max = len;
	return (res);
}

void	print_grid(t_grid * grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("grid {\n\n");
	while (j < grid->y_max)
	{
		while (i < grid->x_max)
		{
			printf("%d ", grid->grid[j][i]);
			i++;
		}
		j++;
		i = 0;
		printf("\n");
	}
	printf("\n}\n");
}