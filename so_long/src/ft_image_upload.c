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

void	putting_img(t_data *data, int i, int j)
{
	if (data->map[i][j] != '1')
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->img0, data->point_x, data->point_y);
	if (data->map[i][j] == 'F' || data->map[i][j] == 'P')
	{
		printf("n = %d\n", data->n);
		if (data->n >= 0 && data->n < 4)
			mlx_put_image_to_window(data->mlx, data->wid,
				data->img->nav[data->n], data->point_x, data->point_y);
		else if (data->n >= 4 && data->n < 8)
			mlx_put_image_to_window(data->mlx, data->wid,
				data->img->nav_m[data->n - 4], data->point_x, data->point_y);
		else if (data->n >= 8 && data->n < 12)
		{
			if (mlx_put_image_to_window(data->mlx, data->wid, data->img->nav_f[data->n - 8], data->point_x, data->point_y))
				printf("aaaaaaaaaaaa %d\n", mlx_put_image_to_window(data->mlx, data->wid, data->img->nav_f[data->n - 8], data->point_x, data->point_y));
		}
	}
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->img1, data->point_x, data->point_y);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->imgc, data->point_x, data->point_y);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->wid,
			data->img->imge, data->point_x, data->point_y);
	// if (data->map[i][j] == 'F' || data->map[i][j] == 'P')
	// {
	// 	if (data->n >= 4 && data->n < 8)
	// 		mlx_put_image_to_window(data->mlx, data->wid,
	// 			data->img->nav[data->n - 4], data->point_x, data->point_y);
	// 	else if (data->n >= 8 && data->n < 12)
	// 		mlx_put_image_to_window(data->mlx, data->wid,
	// 			data->img->nav[data->n - 8], data->point_x, data->point_y);
	// }
}

void	image_upload(t_data *data)
{
	int	i;
	int	j;

	i = 0;
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
}
