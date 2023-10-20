/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:36:12 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/08 16:14:00 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <unistd.h>
# include "keys.h"

typedef struct s_flag
{
	int		flag_win;
	int		flag_song;
	int		flag_fire;
	int		flag_start;
	int		flag_exit; // for exit loop
	int		flag_enter; //for initial portal
	int		flag_first_move; // for first move place

	int		initial_x;
	int		initial_y;
}			t_flag;

typedef struct s_img //struct for images
{
	void	*start;
	void	*start1;
	void	*start2;
	void	*start3;
	void	*start4;
	void	*midpic;
	void	*endpic;

	void	*img1;
	void	*img0;
	void	*imgc;
	void	*imgc1;
	void	*imgp;

	void	**imge;
	void	**nav;
	void	**nav_m;
	void	**nav_f;

	int		img_l;
	int		img_w;
}			t_img;

typedef struct s_data //struct for general variabls 
{
	char	*buff;
	char	**map;
	void	*mlx;
	void	*wid;
	int		win_y;
	int		win_x;

	int		level;
	int		argc;
	char	**argv;

	int		score;
	int		point_x;
	int		point_y;
	int		s;
	int		n; // 0-3 are P's inactive imgs | 4-7 are P's movement imgs | 8-11 are P's fire imgs 
	t_img	*img;
	t_flag	*flag;
}			t_data;

//###################### MLX + PLEY ##############################
void	so_long(t_data *data, char *argv);
void	finish(t_data *event);
void	movement(int key, t_data *evn);
void	key_event(t_data *img);
void	get_img(t_data *data);
void	window_manage(int len, int hight, t_data *data);
int		image_upload(t_data *img);
//################################################################

//################# CHECKING #####################################
int		index_check(t_data *map);
void	ft_map_checking(t_data *map);
void	check_nl(t_data *data,char *str);
void	check_strange_symbole(t_data *str);
void	check_quantity_ep(t_data *map);
void	check_rec(t_data *tab);
//################################################################

//################# UTILS + FREE-INIT ############################
int		len_map_size(t_data *map);
void	cl_count(t_data *map);
int		hight_map_size(char **map);
void	del_nl(t_data *tab);
void	clean_and_exit(t_data *data, int flag, char *err);
void	init_all(t_data *data);
void	ft_map_getting(t_data *map, char *s, int fd);
void	free_double(char ***map);
void	duplicate(char ***dup, char **map);
//################################################################

//################## FT_LIB ######################################
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t l);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	**ft_split(char const *s, char c);
void	ft_putnbr(int nb);
void	fill(char **str, int x, int y, char to_fill);
void	valid_flood_fill_map(char **map, t_data *data);

//################################################################

#endif
