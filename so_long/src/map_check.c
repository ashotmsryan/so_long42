/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*                                                                            */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:03:06 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/10 17:32:14 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checking_ecp(t_data *data)
{
	int	i;
	int	j;
	int	fl_p;
	int	fl_e;
	int	fl_c;

	i = -1;
	fl_p = 0;
	fl_e = 0;
	fl_c = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j] != '\0')
		{
			if (data->map[i][j] == 'P')
				fl_p++;
			if (data->map[i][j] == 'C')
				fl_c = 1;
			if (data->map[i][j] == 'E')
				fl_e = 1;
		}
	}
	if (fl_p != 1 || fl_c == 0 || fl_e == 0)
		clean_and_exit(data, 1, "Special symbole error\n");
}

void	check_strange_symbole(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{	
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
					&& data->map[j][i] != 'P' && data->map[j][i] != 'A'
					&& data->map[j][i] != 'E' && data->map[j][i] != 'C'
					&& data->map[j][i] != '\0')
				clean_and_exit(data, 1, "Strange symbole error\n");
			i++;
		}
		i = 0;
		j++;
	}
}

void	check_borders(t_data *data)
{
	int	i;
	int	j;
	int	hight;

	i = 0;
	hight = hight_map_size(data->map);
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if ((data->map[i][j] == '0' || data->map[i][j] == 'P' || data->map[i][j] == 'A'
				|| data->map[i][j] == 'C' || data->map[i][j] == 'E') && (i == 0 || i == hight - 1
				|| j == (int)ft_strlen(data->map[i]) - 1 || j == 0))
				clean_and_exit(data, 1, "Invalid map\n");
			j++;
		}
		i++;
	}
}

void	check_rec(t_data *data)
{
	int		i;
	int		j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	size = ft_strlen(data->map[i]);
	while (data->map[i] != NULL)
	{
		if (size != ft_strlen(data->map[i]))
			clean_and_exit(data, 1, "The map is not rectangle\n");
		i++;
	}
}

void	ft_map_checking(t_data *data)
{
	char	**map;
	int		height;
	int		weight;

	height = 0;
	weight = 0;
	del_nl(data);
	check_strange_symbole(data);
	check_rec(data);
	check_borders(data);
	checking_ecp(data);
	duplicate(&map, data->map);
	while (map[height][weight] != 'P' && map[height][weight] != 'F')
	{
		height++;
		weight = 0;
		while (map[height][weight] != '\0' && map[height][weight] != 'P'
			&& map[height][weight] != 'F')
			weight++;
	}
	fill(map, weight, height, map[height][weight]);
	valid_flood_fill_map(map, data);
	free_double(&map);
}