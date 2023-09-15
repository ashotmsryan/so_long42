/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_upload.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:04 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/07 14:52:04 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_img_upload(t_data *data)
{

	if (data->flag->flag_enter == 0)
	{
		data->flag->initial_x = data->point_x;
		data->flag->initial_y = data->point_y;
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->imge[0], data->point_x, data->point_y);
		data->flag->flag_first_move = 1;
	}
	else if (data->flag->flag_enter > 0 && data->flag->flag_enter < 3)
	{
		if (data->flag->flag_exit >= 4)
			data->flag->flag_exit = 0;
		if (data->flag->flag_first_move == 1)
			mlx_put_image_to_window(data->mlx, data->wid,
				data->img->img0, data->flag->initial_x, data->flag->initial_y);
		else
			mlx_put_image_to_window(data->mlx, data->wid, 
				data->img->imge[data->flag->flag_exit], data->flag->initial_x, data->flag->initial_y);
		data->flag->flag_exit++;
		data->flag->flag_first_move = 0;
	}
	if (data->flag->flag_fire)
	{
		usleep(300000);
		data->flag->flag_fire = 0;
	}
	if (data->n >= 0 && data->n < 4)
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->nav[data->n], data->point_x, data->point_y);
	else if (data->n >= 4 && data->n < 8)
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->nav_m[data->n - 4], data->point_x, data->point_y);
	else if (data->n >= 8 && data->n < 12)
	{
		mlx_put_image_to_window(data->mlx, data->wid, 
			data->img->nav_f[data->n - 8], data->point_x, data->point_y);
		data->n -= 8;
		data->flag->flag_fire = 1;
	}
}

void	putting_img(t_data *data, int i, int j)
{
	if (data->flag->flag_enter > 2)
		data->flag->initial_x = data->flag->initial_y = 0;
	
	if (data->map[i][j] != '1' && !(data->flag->initial_x == data->point_x && data->flag->initial_y == data->point_y))
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->img0, data->point_x, data->point_y);
	if (data->map[i][j] == 'F' || data->map[i][j] == 'P')
		player_img_upload(data);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->img1, data->point_x, data->point_y);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->imgc, data->point_x, data->point_y);
	else if (data->map[i][j] == 'E')
	{
		if (data->score == 0)
		{
			if (data->flag->flag_exit >= 4)
				data->flag->flag_exit = 0;
			mlx_put_image_to_window(data->mlx, data->wid,
				data->img->imge[data->flag->flag_exit], data->point_x, data->point_y);
			data->flag->flag_exit++;
		}
	}
}

int	image_upload(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->point_x = 0;
	data->point_y = 0;
	while (data->map[i] != NULL)
	{
        j = 0;
		while (data->map[i][j] != '\0')
		{
			putting_img(data, i, j);
			j++;
			data->point_x += data->img->img_l;
		}
		data->point_x = 0;
		data->point_y += data->img->img_w;
		i++;
	}
	return (0);
}
