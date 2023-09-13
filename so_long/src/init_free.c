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
	data->nav = 0;
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		clean_and_exit(data, 1, "Fatal error\n");
	data->img->img1 = 0;
	data->img->img0 = 0;
	data->img->imgc = 0;
	data->img->imgp = 0;
	data->img->imge = 0;
	data->img->img_l = 0;
	data->img->img_w = 0;
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

void	clean_and_exit(t_data *data, int flag, char *err)
{
	if (data->img->imgp)
    	mlx_destroy_image(data->mlx, data->img->imgp);
    if (data->img->img1)
    	mlx_destroy_image(data->mlx, data->img->img1);
    if (data->img->img0)
    	mlx_destroy_image(data->mlx, data->img->img0);
    if (data->img->imgc)
   		mlx_destroy_image(data->mlx, data->img->imgc);
    if (data->img->imge)
    	mlx_destroy_image(data->mlx, data->img->imge);
	if (data->nav && data->nav[0])
    	mlx_destroy_image(data->mlx, data->nav[0]);
	if (data->nav && data->nav[1])
    	mlx_destroy_image(data->mlx, data->nav[1]);
	if (data->nav && data->nav[2])
	    mlx_destroy_image(data->mlx, data->nav[2]);
	if (data->nav && data->nav[3])
    	mlx_destroy_image(data->mlx, data->nav[3]);
	free(data->nav);
	free(data->img);
	free(data->wid);
	free_double(&(data->map));
	write(2, err, ft_strlen(err));
	system("leaks so_long");
	if (flag)
		exit(1);
	exit(0);
}