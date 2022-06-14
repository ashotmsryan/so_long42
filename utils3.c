/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:08:51 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/08 18:58:33 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;
	int	j;

	if (nb < 0)
	{
		ft_putchar ('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		i = nb / 10;
		ft_putnbr (i);
	}
	if (nb == -2147483648)
	{
		write (1, "2147483648", 11);
		return ;
	}
	j = nb % 10 + '0';
	ft_putchar (j);
}

void	check_quantity_ep(t_data *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			j++;
			if (map->map[i][j] == 'P')
				count++;
		}
		i++;
	}
	if (count > 2)
		ft_print_error(8);
}

void	check_nl(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			j = 1;
		i++;
	}
	if (j == 1)
		ft_print_error(9);
}
