/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:17:05 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/10 19:46:56 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	del_nl(t_data *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab->map[i] != NULL)
	{
		while (tab->map[i][j])
		{
			if (tab->map[i][j] == '\n')
				tab->map[i][j] = '\0';
				j++;
		}
		i++;
	}
	return (*tab);
}

void	check_rec(t_data *tab)
{
	int		i;
	int		j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	size = ft_strlen(tab->map[i]);
	while (tab->map[i] != NULL)
	{
		if (size != ft_strlen(tab->map[i]))
			ft_print_error(6);
		i++;
	}
}

void	finish(t_data *event)
{
	int	i;

	i = 0;
	while (event->map[i])
	{
		free(event->map[i]);
		i++;
	}
	free (event->map);
	mlx_destroy_image(event->mlx, event->img1);
	mlx_destroy_image(event->mlx, event->img0);
	mlx_destroy_image(event->mlx, event->imgc);
	mlx_destroy_image(event->mlx, event->imgp);
	mlx_destroy_image(event->mlx, event->imge);
	write(1, "|-------------------------------------|\n", 40);
	write(1, "|YOU SUCCESSFULLY PASSED THE GAME(^_^)|\n", 40);
	write(1, "|-------------------------------------|\n", 40);
	exit(0);
}

int	len_map_size(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i][j] != '\0')
		j++;
	return (j);
}

int	hight_map_size(t_data *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
		i++;
	return (i);
}
