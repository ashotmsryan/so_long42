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

#include "so_long.h"

void	my_while(t_data *img, int i, int j)
{
	if (img->map[i][j] == 'F')
		mlx_put_image_to_window(img->mlx, img->wid,
			img->imgp, img->point_x, img->point_y);
	else if (img->map[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->wid,
			img->img1, img->point_x, img->point_y);
	else if (img->map[i][j] == '0')
		mlx_put_image_to_window(img->mlx, img->wid,
			img->img0, img->point_x, img->point_y);
	else if (img->map[i][j] == 'C')
		mlx_put_image_to_window(img->mlx, img->wid,
			img->imgc, img->point_x, img->point_y);
	else if (img->map[i][j] == 'P')
		mlx_put_image_to_window(img->mlx, img->wid,
			img->imgp, img->point_x, img->point_y);
	else if (img->map[i][j] == 'E')
		mlx_put_image_to_window(img->mlx, img->wid,
			img->imge, img->point_x, img->point_y);
}

void	image_upload(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img->map[i] != NULL)
	{
		while (img->map[i][j] != '\0')
		{
			my_while(img, i, j);
			j++;
			img->point_x += img->img_l;
		}
		img->point_x = 0;
		img->point_y += img->img_w;
		j = 0;
		i++;
	}
}
