#include "../so_long.h"

void init_all(t_data *data)
{	
	data->buff = 0;
	data->s = 0;
	data->wid = 0;
	data->score = 0;
	data->point_x = 0;
	data->point_y = 0;
	data->map = 0;
	data->n = 0;
	data->level = 0;
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		clean_and_exit(data, 1, "Fatal error\n");
	data->img->nav = 0;
	data->img->nav_m = 0;
	data->img->nav_f = 0;
    data->img->die = 0;
    data->img->img1 = 0;
	data->img->img0 = 0;
	data->img->imgc = 0;
	data->img->imgc1 = 0;
	data->img->imgp = 0;
	data->img->imge = 0;
	data->img->endpic = 0;
	data->img->losepic = 0;
	data->img->midpic = 0;
	data->img->img_l = 0;
	data->img->img_w = 0;
	data->flag = malloc(sizeof(t_img));
	if (!data->flag)
		clean_and_exit(data, 1, "Fatal error\n");
	data->flag->flag_win = 0;
	data->flag->flag_die = 0;
	data->flag->flag_song = 3;
	data->flag->flag_fire = 0;
	data->flag->flag_exit = 0;
	data->flag->flag_start = 5;
	data->flag->flag_enter = 0;
	data->flag->initial_x = 0;
	data->flag->initial_y = 0;
	data->flag->flag_first_move = 0;
}

void	free_double(char ***map)
{
	int i = -1;
	while(map && *map && (*map)[++i])
	{
		free((*map)[i]);
		(*map)[i] = 0;
	}
	free(*map);
	*map = 0;
}

void	clean_and_exit(t_data *data, int flag, char *err) // 0 if passed game | 1 if error | 2 if closed
{
	if (flag)
		write(2, err, ft_strlen(err));
	free_double(&(data->map));
	// system("leaks so_long");
	if (flag)
	{
        if (data->img->losepic)
			mlx_destroy_image(data->mlx, data->img->losepic);
		if (data->img->endpic)
			mlx_destroy_image(data->mlx, data->img->endpic);
		if (data->img->midpic)
			mlx_destroy_image(data->mlx, data->img->midpic);
		if (data->img->start)
			mlx_destroy_image(data->mlx, data->img->start);
		if (data->img->start1)
			mlx_destroy_image(data->mlx, data->img->start1);
		if (data->img->start2)
			mlx_destroy_image(data->mlx, data->img->start2);
		if (data->img->start3)
			mlx_destroy_image(data->mlx, data->img->start3);
		if (data->img->start4)
			mlx_destroy_image(data->mlx, data->img->start4);

		if (data->img->die)
			mlx_destroy_image(data->mlx, data->img->die);
		if (data->img->img1)
			mlx_destroy_image(data->mlx, data->img->img1);
		if (data->img->img0)
			mlx_destroy_image(data->mlx, data->img->img0);
		if (data->img->imgc)
			mlx_destroy_image(data->mlx, data->img->imgc);
		if (data->img->imgc1)
			mlx_destroy_image(data->mlx, data->img->imgc1);

		if (data->img->imge[0])
			mlx_destroy_image(data->mlx, data->img->imge[0]);
		if (data->img->imge[1])
			mlx_destroy_image(data->mlx, data->img->imge[1]);
		if (data->img->imge[2])
			mlx_destroy_image(data->mlx, data->img->imge[2]);
		if (data->img->imge[3])
			mlx_destroy_image(data->mlx, data->img->imge[3]);	

		if (data->img->nav && data->img->nav[0])
			mlx_destroy_image(data->mlx, data->img->nav[0]);
		if (data->img->nav && data->img->nav[1])
			mlx_destroy_image(data->mlx, data->img->nav[1]);
		if (data->img->nav && data->img->nav[2])
			mlx_destroy_image(data->mlx, data->img->nav[2]);
		if (data->img->nav && data->img->nav[3])
			mlx_destroy_image(data->mlx, data->img->nav[3]);
		
		if (data->img->nav_m && data->img->nav_m[0])
			mlx_destroy_image(data->mlx, data->img->nav_m[0]);
		if (data->img->nav_m && data->img->nav_m[1])
			mlx_destroy_image(data->mlx, data->img->nav_m[1]);
		if (data->img->nav_m && data->img->nav_m[2])
			mlx_destroy_image(data->mlx, data->img->nav_m[2]);
		if (data->img->nav_m && data->img->nav_m[3])
			mlx_destroy_image(data->mlx, data->img->nav_m[3]);

		if (data->img->nav_f && data->img->nav_f[0])
			mlx_destroy_image(data->mlx, data->img->nav_f[0]);
		if (data->img->nav_f && data->img->nav_f[1])
			mlx_destroy_image(data->mlx, data->img->nav_f[1]);
		if (data->img->nav_f && data->img->nav_f[2])
			mlx_destroy_image(data->mlx, data->img->nav_f[2]);
		if (data->img->nav_f && data->img->nav_f[3])
			mlx_destroy_image(data->mlx, data->img->nav_f[3]);

		free(data->img->nav);
		data->img->nav = 0;
		free(data->img->nav_m);
		data->img->nav_m = 0;
		free(data->img->nav_f);
		data->img->nav_f = 0;
		free(data->img->imge);
		data->img->imge = 0;
		free(data->img);
		data->img = 0;
		free(data->flag);
		data->flag = 0;
		free(data->wid);
		data->wid = 0;
		if (data->os)
			system("killall mpg123");
		else
			system("killall afplay");
		if (flag == 1)
			exit(1);
		
		exit(0);
	}
	mlx_destroy_window(data->mlx, data->wid);
	data->wid = 0;
	if (data->flag->flag_die)
		data->flag->flag_start = -2;
	else if (data->level + 1 == data->argc)
		data->flag->flag_start = -3;
    else
	{
		data->level++;
		data->flag->flag_start = -1;
	}
	data->flag->flag_first_move = 0;
	data->flag->flag_enter = 0;
	printf("level = %d\n", data->level);
	so_long(data, data->argv[data->level + 1]);
}