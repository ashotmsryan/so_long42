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

#include "so_long.h"
#include <mlx.h>

t_data	*open_wd(t_data *ig)
{
	ig->img_wl = "img/wall.xpm";
	ig->img_g = "img/ground.xpm";
	ig->img_c = "img/c.xpm";
	ig->img_p = "img/p.xpm";
	ig->img_e = "img/e.xpm";
	ig->img1 = mlx_xpm_file_to_image(ig->mlx, ig->img_wl,
			&ig->img_w, &ig->img_l);
	ig->img0 = mlx_xpm_file_to_image(ig->mlx, ig->img_g,
			&ig->img_w, &ig->img_l);
	ig->imgc = mlx_xpm_file_to_image(ig->mlx, ig->img_c,
			&ig->img_w, &ig->img_l);
	ig->imgp = mlx_xpm_file_to_image(ig->mlx, ig->img_p,
			&ig->img_w, &ig->img_l);
	ig->imge = mlx_xpm_file_to_image(ig->mlx, ig->img_e,
			&ig->img_w, &ig->img_l);
	return (ig);
}

void	window_manage(int len, int hight, t_data *map)
{
	t_data	img;
	int		x;
	int		y;

	img = *map;
	img.mlx = mlx_init();
	img = *open_wd(&img);
	x = len * img.img_l;
	y = hight * img.img_w;
	img.wid = mlx_new_window(img.mlx, x, y, "so_long");
	image_upload(&img);
	key_event(&img);
	mlx_loop(img.mlx);
}

void	cl_size(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	map->score = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'C')
				map->score++;
			j++;
		}
		i++;
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		hight;
	t_data	map;

	map.s = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_print_error(2);
		map.map = ft_map_checking(&map, argv[1], fd);
		close(fd);
		cl_size(&map);
		len = len_map_size(&map);
		hight = hight_map_size(&map);
		window_manage(len, hight, &map);
	}
	else
		ft_print_error(7);
	return (0);
}
