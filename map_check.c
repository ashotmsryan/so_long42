/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:03:06 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/10 17:32:14 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checking_ecp(t_data *tab)
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
	while (tab->map[++i])
	{
		j = 0;
		while (tab->map[i][j++] != '\0')
		{
			if (tab->map[i][j] == 'P')
				fl_p = 1;
			if (tab->map[i][j] == 'C')
				fl_c = 1;
			if (tab->map[i][j] == 'E')
				fl_e = 1;
		}
	}
	if (fl_p == 0 || fl_c == 0 || fl_e == 0)
		ft_print_error(4);
}

void	row_index_check(t_data *tab, int end)
{
	int	i;
	int	fl;

	i = 0;
	fl = 1;
	end--;
	while (tab->map[i + 1] != NULL)
	{
		if (tab->map[i][end] != '1' || tab->map[i][0] != '1')
			fl = 0;
		i++;
	}
	if (fl == 0)
		ft_print_error(3);
	check_quantity_ep(tab);
	checking_ecp(tab);
}

void	check_strange_symbole(t_data *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str->map[j] != NULL)
	{
		while (str->map[j][i] != '\0')
		{	
			if (str->map[j][i] != '1' && str->map[j][i] != '0'
					&& str->map[j][i] != 'P'
					&& str->map[j][i] != 'E' && str->map[j][i] != 'C'
					&& str->map[j][i] != '\n' && str->map[j][i] != '\0')
				ft_print_error(5);
			i++;
		}
		i = 0;
		j++;
	}
}

void	col_index_check(t_data *tab)
{
	int	i;
	int	j;
	int	end;

	check_strange_symbole(tab);
	i = 0;
	j = 0;
	*tab = del_nl(tab);
	check_rec(tab);
	while (tab->map[i] != NULL)
	{
		while (tab->map[i][j] != '\0')
		{
			if (tab->map[0][j] != '1' || (tab->map[i + 1] == NULL
							&& tab->map[i][j] != '1'))
				ft_print_error(3);
			j++;
		}
		i++;
		end = j;
		j = 0;
	}
	row_index_check(tab, end);
}

char	**ft_map_checking(t_data *map, char *s, int fd)
{
	char	*smap;
	char	*str;

	str = NULL;
	if (ft_strncmp(".ber", s + ft_strlen(s) - 4, 4) != 0)
		ft_print_error(1);
	while (1)
	{
		smap = get_next_line(fd);
		if (!str)
			str = ft_strdup(smap);
		else
			str = ft_strjoin(str, smap);
		if (str[0] == '\0' || str[0] != '1')
			ft_print_error(10);
		if (*smap == (char) NULL)
			break ;
	}
	check_nl(str);
	map->map = ft_split(str, '\n');
	free (str);
	col_index_check(map);
	return (map->map);
}
