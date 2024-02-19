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

#include "../so_long.h"

void	going_up(t_data *data, int i, int j)
{
	if (data->map[i - 1][j] != '1')
	{
		data->s++;
		printf("%d\n",data->s);
		data->n = 4;
		if (data->map[i - 1][j] == 'C')
			data->score--;
		if (data->map[i - 1][j] == 'E' && data->score != 0)
		{
			data->map[i][j] = '0';
			data->map[--i][j] = 'F';
		}
		else if (data->map[i - 1][j] == 'E' && data->score == 0)
			finish(data);
		else
		{
			if ((data->map[i - 1][j] == '0' || data->map[i - 1][j] == 'C')
					&& data->map[i][j] == 'F')
				data->map[i][j] = 'E';
			else
				data->map[i][j] = '0';
		    data->map[--i][j] = 'P';
		}
	}
}

void	going_left(t_data *data, int i, int j)
{
	if (data->map[i][j - 1] != '1')
	{
		data->s++;
		data->n = 5;
        printf("%d\n",data->s);
		if (data->map[i][j - 1] == 'C')
			data->score--;
		if (data->map[i][j - 1] == 'E' && data->score != 0)
		{
			data->map[i][j] = '0';
			data->map[i][--j] = 'F';
		}
		else if (data->map[i][j - 1] == 'E' && data->score == 0)
			finish(data);
		else
		{
			if ((data->map[i][j - 1] == '0' || data->map[i][j - 1] == 'C')
					&&data->map[i][j] == 'F')
				data->map[i][j] = 'E';
			else
				data->map[i][j] = '0';
			data->map[i][--j] = 'P';
		}
	}
}

void	going_dawn(t_data *data, int i, int j)
{
	if (data->map[i + 1][j] != '1')
	{
		data->s++;
		data->n = 6;
		printf("%d\n",data->s);
		if (data->map[i + 1][j] == 'C')
			data->score--;
		if (data->map[i + 1][j] == 'E' && data->score != 0)
		{
			data->map[i][j] = '0';
			data->map[++i][j] = 'F';
		}
		else if (data->map[i + 1][j] == 'E' && data->score == 0)
			finish(data);
		else
		{
			if ((data->map[i + 1][j] == '0' || data->map[i + 1][j] == 'C')
					&& data->map[i][j] == 'F')
				data->map[i][j] = 'E';
			else
				data->map[i][j] = '0';
			data->map[++i][j] = 'P';
		}
	}
}

void	going_right(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] != '1')
	{
		data->s++;
		data->n = 7;
		printf("%d\n",data->s);
		if (data->map[i][j + 1] == 'C')
			data->score--;
		if (data->map[i][j + 1] == 'E' && data->score != 0)
		{
			data->map[i][j] = '0';
			data->map[i][++j] = 'F';
		}
		else if (data->map[i][j + 1] == 'E' && data->score == 0)
			finish(data);
		else
		{
			if ((data->map[i][j + 1] == '0' || data->map[i][j + 1] == 'C')
					&& data->map[i][j] == 'F')
				data->map[i][j] = 'E';
			else
				data->map[i][j] = '0';
			data->map[i][++j] = 'P';
		}
	}
}

void	movement(int key, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->flag->flag_start == 0)
	{
		while (data->map[i][j] != 'P' && data->map[i][j] != 'F')
		{
			i++;
			j = 0;
			while (data->map[i][j] != 'P' && data->map[i][j] != 'F'
					&& data->map[i][j] != '\0')
				j++;
		}
		data->flag->flag_enter++;
		if (key == UP || key == UP1)
		{
			data->n = 0;
			if (key == UP1)
				going_up(data, i, j);
		}
		else if (key == LEFT || key == LEFT1)
		{
			data->n = 1;
			if (key == LEFT1)
				going_left(data, i, j);
		}
		else if (key == DOWN || key == DOWN1)
		{
			data->n = 2;
			if (key == DOWN1)
				going_dawn(data, i, j);
		}
		else if (key == RIGHT || key == RIGHT1)
		{
			data->n = 3;
			if (key == RIGHT1)
				going_right(data, i, j);
		}
	}
}