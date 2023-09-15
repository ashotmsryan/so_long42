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

void	get_img(t_data *data)
{
	data->img->img1 = mlx_xpm_file_to_image(data->mlx, "resources/wall.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->img0 = mlx_xpm_file_to_image(data->mlx, "resources/ground1.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imgc = mlx_xpm_file_to_image(data->mlx, "resources/c.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imge = mlx_xpm_file_to_image(data->mlx, "resources/e1.xpm", \
		&data->img->img_w, &data->img->img_l);

	data->img->nav = (void**)malloc(4 * sizeof(void*));
	if (!data->img->nav)
		clean_and_exit(data, 1, "Fatal error\n");
	data->img->nav[0] = mlx_xpm_file_to_image(data->mlx, "resources/pn.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav[1] = mlx_xpm_file_to_image(data->mlx, "resources/pw.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav[2] = mlx_xpm_file_to_image(data->mlx, "resources/ps.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav[3] = mlx_xpm_file_to_image(data->mlx, "resources/pe.xpm", \
		&data->img->img_w, &data->img->img_l);


	data->img->nav_m = (void**)malloc(4 * sizeof(void*));
	if (!data->img->nav_m)
		clean_and_exit(data, 1, "Fatal error\n");
	data->img->nav_m[0] = mlx_xpm_file_to_image(data->mlx, "resources/pnm.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav_m[1] = mlx_xpm_file_to_image(data->mlx, "resources/pwm.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav_m[2] = mlx_xpm_file_to_image(data->mlx, "resources/psm.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav_m[3] = mlx_xpm_file_to_image(data->mlx, "resources/pem.xpm", \
		&data->img->img_w, &data->img->img_l);

	data->img->nav_f = (void**)malloc(4 * sizeof(void*));
	if (!data->img->nav_f)
		clean_and_exit(data, 1, "Fatal error\n");
	data->img->nav_f[0] = mlx_xpm_file_to_image(data->mlx, "resources/pnf.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav_f[1] = mlx_xpm_file_to_image(data->mlx, "resources/pwf.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav_f[2] = mlx_xpm_file_to_image(data->mlx, "resources/psf.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->nav_f[3] = mlx_xpm_file_to_image(data->mlx, "resources/pef.xpm", \
		&data->img->img_w, &data->img->img_l);

	data->img->imge = (void**)malloc(4 * sizeof(void*));
	if (!data->img->imge)
		clean_and_exit(data, 1, "Fatal error\n");
	data->img->imge[0] = mlx_xpm_file_to_image(data->mlx, "resources/e1.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imge[1] = mlx_xpm_file_to_image(data->mlx, "resources/e2.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imge[2] = mlx_xpm_file_to_image(data->mlx, "resources/e3.xpm", \
		&data->img->img_w, &data->img->img_l);
	data->img->imge[3] = mlx_xpm_file_to_image(data->mlx, "resources/e4.xpm", \
		&data->img->img_w, &data->img->img_l);

    if (!data->img->nav[0] || !data->img->nav[1] || !data->img->nav[2] || !data->img->nav[3]
        || !data->img->nav_m[0] || !data->img->nav_m[1] || !data->img->nav_m[2] || !data->img->nav_m[3]
        || !data->img->imge[0] || !data->img->imge[1] || !data->img->imge[2] || !data->img->imge[3]
        || !data->img->nav_f[0] || !data->img->nav_f[1] || !data->img->nav_f[2] || !data->img->nav_f[3]
		|| !data->img->img1 || !data->img->img0 || !data->img->imgc || !data->img->imge)
		clean_and_exit(data, 1, "Resource error\n");;
}