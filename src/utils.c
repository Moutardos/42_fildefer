/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:46:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/13 13:10:50 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int	*strtoi(const char *str, int *x_max)
{
	char			**to_atoi;
	int				*res;
	unsigned int	len;
	unsigned int	i;

	to_atoi = ft_split(str, ' ');
	if (!to_atoi)
		return (NULL);
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
	*x_max = len;
	return (free_split(to_atoi), res);
}

/*
void	print_grid(t_gridinfo *grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("grid {\n\n");
	while (j < grid->y_max)
	{
		while (i < grid->x_max)
		{
			ft_printf("(%.3f,%.3f,%.3f)  ", 
			grid->grid[j][i].x, grid->grid[j][i].y, grid->grid[j][i].z);
			i++;
		}
		j++;
		i = 0;
		ft_printf("\n");
	}
	ft_printf("\n}\n");
}
*/
int	get_max(int *arr, int len)
{
	int	i;
	int	max;

	max = INT_MIN;
	i = 0;
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	free_split(char **s)
{
	char	**curr;

	curr = s;
	while (*curr)
	{
		free(*curr);
		curr++;
	}
	free(s);
}
