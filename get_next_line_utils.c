/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:32:40 by amsryan           #+#    #+#             */
/*   Updated: 2022/05/17 14:33:09 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*k;
	char	l;

	l = c;
	k = (char *)s;
	i = 0;
	if (!s)
		return (0);
	while (k[i] != '\0' && k[i] != l)
		i++;
	if (k[i] == l)
	{
		return (&k[i]);
	}
	return (0);
}
