/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:21 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/10 19:46:01 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pressing_key(int key, t_data *event)
{
	int	i;

	if (key == 53)
	{
		i = -1;
		while (event->map[++i])
			free(event->map[i]);
		free (event->map);
		mlx_destroy_image(event->mlx, event->img1);
		mlx_destroy_image(event->mlx, event->img0);
		mlx_destroy_image(event->mlx, event->imgc);
		mlx_destroy_image(event->mlx, event->imgp);
		mlx_destroy_image(event->mlx, event->imge);
		write(1, "|--------------------------|\n", 30);
		write(1, "|YOU EXITED SUCCESSFULLY!!!|\n", 30);
		write(1, "|--------------------------|\n", 30);
		exit(0);
	}
	else if (key == 13 || key == 1 || key == 0 || key == 2
		|| key == 126 || key == 125 || key == 123 || key == 124)
		movement(key, event);
	return (0);
}

int	exit_game(t_data *event)
{
	int	i;

	i = -1;
	while (event->map[++i])
		free(event->map[i]);
	free (event->map);
	mlx_destroy_image(event->mlx, event->img1);
	mlx_destroy_image(event->mlx, event->img0);
	mlx_destroy_image(event->mlx, event->imgc);
	mlx_destroy_image(event->mlx, event->imgp);
	mlx_destroy_image(event->mlx, event->imge);
	write(1, "|--------------------------|\n", 30);
	write(1, "|YOU EXITED SUCCESSFULLY!!!|\n", 30);
	write(1, "|--------------------------|\n", 30);
	exit(0);
}

void	key_event(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_hook (img->wid, 2, 1l << 2, pressing_key, img);
	mlx_hook (img->wid, 17, 1l << 17, exit_game, img);
}
