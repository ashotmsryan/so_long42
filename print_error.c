/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:49:05 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/08 19:04:05 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (2, &s[i], 1);
		i++;
	}
}

int	ft_print_error(int err_nbr)
{
	if (err_nbr == 1)
		ft_putstr("file_type_error\n");
	else if (err_nbr == 2)
		ft_putstr("fd_error\n");
	else if (err_nbr == 3)
		ft_putstr("incorrect_wall_construction_error\n");
	else if (err_nbr == 4)
		ft_putstr("undetected_symbole_error\n");
	else if (err_nbr == 5)
		ft_putstr("strange_symbole_error\n");
	else if (err_nbr == 6)
		ft_putstr("not_rectangle_error\n");
	else if (err_nbr == 7)
		ft_putstr("no/toomany_map_error\n");
	else if (err_nbr == 8)
		ft_putstr("too_many_e/p_error\n");
	else if (err_nbr == 9)
		ft_putstr("empty_nl_error\n");
	else if (err_nbr == 10)
		ft_putstr("empty_file_error\n");
	exit(1);
}
