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
# include <unistd.h>

typedef struct s_data
{
	int		s;
	char	**map;
	char	*img_wl;
	char	*img_g;
	char	*img_c;
	char	*img_p;
	char	*img_e;
	void	*mlx;
	void	*img1;
	void	*img0;
	void	*imgc;
	void	*imgp;
	void	*imge;
	void	*ptr_img;
	void	*wid;
	int		img_l;
	int		img_w;
	int		score;
	int		point_x;
	int		point_y;
}			t_data;

int		index_check(t_data *map);
int		len_map_size(t_data *map);
int		hight_map_size(t_data *map);
int		ft_print_error(int err_nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_map_checking(t_data *map, char *s, int fd);
size_t	ft_strlen(char *str);
void	ft_putnbr(int nb);
void	check_nl(char *str);
void	check_quantity_ep(t_data *map);
void	finish(t_data *event);
void	movement(int key, t_data *evn);
void	key_event(t_data *img);
void	check_strange_symbole(t_data *str);
void	check_rec(t_data *tab);
void	image_upload(t_data *img);
void	window_manage(int len, int hight, t_data *map);
t_data	del_nl(t_data *tab);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t l);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	**ft_split(char const *s, char c);

#endif
