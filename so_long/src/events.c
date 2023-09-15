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
	int	i;
	int	j;
	
	i = 0;
	j = 0;
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

	if (key == 53)
		clean_and_exit(data, 0, buff);
	else if (key == 13 || key == 1 || key == 0 || key == 2
		|| key == 126 || key == 125 || key == 123 || key == 124)
		movement(key, data);
	else if (key == 49)
		fire(data);
	return (0);
}

int	exit_game(t_data *data)
{
    char buff[] = "|--------------------------|\n|YOU EXITED SUCCESSFULLY!!!|\n|--------------------------|\n"; 
    clean_and_exit(data, 0, buff);
    return (0);
}

void	key_event(t_data *data)
{
	mlx_loop_hook(data->mlx, image_upload, data);
	mlx_hook (data->wid, 2, 1l << 2, pressing_key, data);
	mlx_hook (data->wid, 17, 1l << 17, exit_game, data);
}
