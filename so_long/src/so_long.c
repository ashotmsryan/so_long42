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

void	window_manage(int len, int hight, t_data *data)
{
	if (data->flag->flag_start == 0)
	{
		data->win_x = len * data->img->img_l;
		data->win_y = hight * data->img->img_w;
	}
	else
	{
		data->win_x = 1440;
		data->win_y = 900;
	}
	if (!data->wid)
		data->wid = mlx_new_window(data->mlx, data->win_x, data->win_y, "so_long");
	image_upload(data);
	key_event(data);
	mlx_loop(data->mlx);
}

void	ft_map_getting(t_data *data, char *s, int fd)
{
	char	*smap;
	char	*str;

	str = NULL;
	if (ft_strncmp(".ber", s + ft_strlen(s) - 4, 4) != 0)
		clean_and_exit(data, 1, "Wrong file type\n");
	while (1)
	{
		smap = get_next_line(fd);
		if (!str)
			str = ft_strdup(smap);
		else
			str = ft_strjoin(str, smap);
		if (str[0] == '\0' || str[0] != '1')
		{
			free(str);
			free(smap);
			clean_and_exit(data, 1, "Invalid map\n");
		}
		if (*smap == '\0')
			break ;
		free(smap);
	}
	check_nl(data, str);
	data->map = ft_split(str, '\n');
	free (str);
	free(smap);

}

void	so_long(t_data *data, char *path)
{
	int		fd;
	int		len;
	int		hight;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		clean_and_exit(data, 1, "Can not open file\n");
	if (!data->map)
	{
		ft_map_getting(data, path, fd);
		ft_map_checking(data);
		cl_count(data);
	}
	close(fd);
	len = ft_strlen(data->map[0]);
	hight = hight_map_size(data->map);
	window_manage(len, hight, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

    #ifdef __linux__
        data.os = 1;
    #elif defined(__APPLE__)
        data.os = 0;
		#endif
	data.argc = argc - 1;
	data.argv = argv;
	init_all(&data);
	if (argc > 1)
	{
		data.mlx = mlx_init();
		get_img(&data);
		so_long(&data, argv[1]);
	}
	else
		clean_and_exit(&data, 1, "Wrong number of arguments\n");
	return (0);
}
