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
	int		x;
	int		y;

	data->mlx = mlx_init();
	get_img(data);
	x = len * data->img->img_l;
	y = hight * data->img->img_w;
	printf("%d\n%d\n", x,y);
	data->wid = mlx_new_window(data->mlx, x, y, "so_long");
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

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		hight;
	t_data	data;

	init_all(&data);
	data.argc = argc - 1;
	if (argc > 1)
	{
		while(data.level < argc - 1)
		{
			fd = open(argv[data.level + 1], O_RDONLY);
			if (fd == -1)
				clean_and_exit(&data, 1, "Can not open file\n");
			ft_map_getting(&data, argv[data.level + 1], fd);
			ft_map_checking(&data);
			close(fd);
			cl_count(&data);
			len = ft_strlen(data.map[0]);
			hight = hight_map_size(data.map);
			window_manage(len, hight, &data);
			data.level++;
		}
	}
	else
		clean_and_exit(&data, 1, "Wrong number of arguments\n");
	return (0);
}
