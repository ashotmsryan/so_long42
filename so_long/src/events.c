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

#include "../so_long.h"

void	finish(t_data *data)
{
	char buff[] = "|-------------------------------------|\n|YOU SUCCESSFULLY PASSED THE GAME(^_^)|\n|-------------------------------------|\n";
	clean_and_exit(data, 0, buff);
}

void	fire(t_data *data)
{
	if (data->n >= 0 && data->n < 4)
		data->n = data->n + 8;
	else if(data->n >= 4 && data->n < 8)
		data->n = data->n + 4;
	// while(data->map && data->map[i])
	// {
	// 	j = 0;
	// 	while(data->map[i][j])
	// 	{

	// 	}
	// }
}

int	pressing_key(int key, t_data *data)
{
    char buff[] = "|--------------------------|\n|YOU EXITED SUCCESSFULLY!!!|\n|--------------------------|\n"; 
	printf("%d\n", key);
	if (key == ENTER && data->flag->flag_start)
	{
		if (data->flag->flag_start == -2 && data->level + 1 == data->argc)
			clean_and_exit(data, 2, "You won!\n");
		if (data->flag->flag_start == -1)
			data->flag->flag_start = 0;
		else
		{
			if (data->flag->flag_song == 3)
			{
				if (data->os)
					system("mpg123 ./resources/HansZimmer-CornfieldChase.mp3 & ");
                else
					system("afplay ./resources/HansZimmer-CornfieldChase.mp3 & ");
				data->flag->flag_song--;
			}
			data->flag->flag_start--;
		}
		if (data->flag->flag_start == 0)
		{
			if (data->wid)
				mlx_destroy_window(data->mlx, data->wid);
			data->wid = 0;
			so_long(data, data->argv[data->level + 1]);
		}
		mlx_clear_window(data->mlx, data->wid);
	}
	if (key == ESC)
		clean_and_exit(data, 2, buff);
	else if (key == UP || key == UP1 || key == DOWN || key == DOWN1
		|| key == LEFT || key == LEFT1 || key == RIGHT || key == RIGHT1)
		movement(key, data);
	else if (key == SPACE)
		fire(data);
	return (0);
}

int	exit_game(t_data *data)
{
    char buff[] = "|--------------------------|\n|YOU EXITED SUCCESSFULLY!!!|\n|--------------------------|\n"; 
    clean_and_exit(data, 2, buff);
    return (0);
}

void	key_event(t_data *data)
{
	mlx_loop_hook(data->mlx, image_upload, data);
	mlx_hook (data->wid, 2, 1l << 0, pressing_key, data);
	mlx_hook (data->wid, 17, 1l << 17, exit_game, data);
}
