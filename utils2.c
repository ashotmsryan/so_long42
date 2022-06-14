/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:28:28 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/08 18:54:09 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	going_up(t_data *evn, int i, int j)
{
	if (evn->map[i - 1][j] != '1')
	{
		evn->s++;
		ft_putnbr(evn->s);
		write(1, "\n", 1);
		if (evn->map[i - 1][j] == 'C')
			evn->score--;
		if (evn->map[i - 1][j] == 'E' && evn->score != 0)
		{
			evn->map[i][j] = '0';
			evn->map[--i][j] = 'F';
		}
		else if (evn->map[i - 1][j] == 'E' && evn->score == 0)
			finish(evn);
		else
		{
			if ((evn->map[i - 1][j] == '0' || evn->map[i - 1][j] == 'C')
					&& evn->map[i][j] == 'F')
				evn->map[i][j] = 'E';
			else
				evn->map[i][j] = '0';
			evn->map[--i][j] = 'P';
		}
	}
}

void	going_left(t_data *evn, int i, int j)
{
	if (evn->map[i][j - 1] != '1')
	{
		evn->s++;
		ft_putnbr(evn->s);
		write(1, "\n", 1);
		if (evn->map[i][j - 1] == 'C')
			evn->score--;
		if (evn->map[i][j - 1] == 'E' && evn->score != 0)
		{
			evn->map[i][j] = '0';
			evn->map[i][--j] = 'F';
		}
		else if (evn->map[i][j - 1] == 'E' && evn->score == 0)
			finish(evn);
		else
		{
			if ((evn->map[i][j - 1] == '0' || evn->map[i][j - 1] == 'C')
					&& evn->map[i][j] == 'F')
				evn->map[i][j] = 'E';
			else
				evn->map[i][j] = '0';
			evn->map[i][--j] = 'P';
		}
	}
}

void	going_dawn(t_data *evn, int i, int j)
{
	if (evn->map[i + 1][j] != '1')
	{
		evn->s++;
		ft_putnbr(evn->s);
		write(1, "\n", 1);
		if (evn->map[i + 1][j] == 'C')
			evn->score--;
		if (evn->map[i + 1][j] == 'E' && evn->score != 0)
		{
			evn->map[i][j] = '0';
			evn->map[++i][j] = 'F';
		}
		else if (evn->map[i + 1][j] == 'E' && evn->score == 0)
			finish(evn);
		else
		{
			if ((evn->map[i + 1][j] == '0' || evn->map[i + 1][j] == 'C')
					&& evn->map[i][j] == 'F')
				evn->map[i][j] = 'E';
			else
				evn->map[i][j] = '0';
			evn->map[++i][j] = 'P';
		}
	}
}

void	going_right(t_data *evn, int i, int j)
{
	if (evn->map[i][j + 1] != '1')
	{
		evn->s++;
		ft_putnbr(evn->s);
		write(1, "\n", 1);
		if (evn->map[i][j + 1] == 'C')
			evn->score--;
		if (evn->map[i][j + 1] == 'E' && evn->score != 0)
		{
			evn->map[i][j] = '0';
			evn->map[i][++j] = 'F';
		}
		else if (evn->map[i][j + 1] == 'E' && evn->score == 0)
			finish(evn);
		else
		{
			if ((evn->map[i][j + 1] == '0' || evn->map[i][j + 1] == 'C')
					&& evn->map[i][j] == 'F')
				evn->map[i][j] = 'E';
			else
				evn->map[i][j] = '0';
			evn->map[i][++j] = 'P';
		}
	}
}

void	movement(int key, t_data *evn)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (evn->map[i][j] != 'P' && evn->map[i][j] != 'F')
	{
		i++;
		j = 0;
		while (evn->map[i][j] != 'P' && evn->map[i][j] != 'F'
				&& evn->map[i][j] != '\0')
			j++;
	}
	if (key == 13 || key == 126)
		going_up(evn, i, j);
	else if (key == 0 || key == 123)
		going_left(evn, i, j);
	else if (key == 1 || key == 125)
		going_dawn(evn, i, j);
	else if (key == 2 || key == 124)
		going_right(evn, i, j);
	evn->point_x = 0;
	evn->point_y = 0;
	image_upload(evn);
}
