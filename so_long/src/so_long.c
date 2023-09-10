/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:52:07 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/10 18:56:16 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_wd(t_data *data)
{
	data->img->img1 = mlx_xpm_file_to_image(data->mlx, "resources/wall.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->img0 = mlx_xpm_file_to_image(data->mlx, "resources/ground.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imgc = mlx_xpm_file_to_image(data->mlx, "resources/c.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imgp = mlx_xpm_file_to_image(data->mlx, "resources/p.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imge = mlx_xpm_file_to_image(data->mlx, "resources/e.xpm", \
		&data->img->img_w, &data->img->img_l);
	if (!data->img->img1 || !data->img->img0 || !data->img->imgc
		|| !data->img->imgp || !data->img->imge)
		clean_and_exit(data, 1, "Resource error\n");
}

void	window_manage(int len, int hight, t_data *data)
{
	int		x;
	int		y;

	data->mlx = mlx_init();
	open_wd(data);
	x = len * data->img->img_l;
	y = hight * data->img->img_w;
	data->wid = mlx_new_window(data->mlx, x, y, "so_long");
	image_upload(data);
	key_event(data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		hight;
	t_data	data;

	init_all(&data);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			clean_and_exit(&data, 1, "Can not open file\n");
		ft_map_getting(&data, argv[1], fd);
		ft_map_checking(&data);
		close(fd);
		cl_count(&data);
		len = ft_strlen(data.map[0]);
		hight = hight_map_size(data.map);
		window_manage(len, hight, &data);
		system("leaks so_long");
	}
	else
		clean_and_exit(&data, 1, "Wrong number of arguments\n");
	return (0);
}
