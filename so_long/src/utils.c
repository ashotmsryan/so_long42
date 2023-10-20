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

#include "../so_long.h"

void	del_nl(t_data *tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab->map[i] != NULL)
	{
		j = 0;
		while (tab->map[i][j])
		{
			if (tab->map[i][j] == '\n')
				tab->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	check_nl(t_data *data, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			j = 1;
		i++;
	}
	if (j == 1)
	{
		free(str);
		clean_and_exit(data, 1, "Empty nl error\n");
	}
}

void	duplicate(char ***dup, char **map)
{
	int	i;

	*dup = (char**) malloc((hight_map_size(map) + 1) * sizeof(char *));
	i = -1;
	while(map && map[++i])
		(*dup)[i] = ft_strdup(map[i]);
	(*dup)[i] = NULL;
}

void	cl_count(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	map->score = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'C')
				map->score++;
			j++;
		}
		i++;
	}
}

int	hight_map_size(char **map)
{
	int	i;

	i = 0;
	while (map && map[i] != NULL)
		i++;
	return (i);
}
