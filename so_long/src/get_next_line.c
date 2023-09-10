/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:19:52 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/10 18:29:48 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*mywhile(int fd, long readsize, char *sline)
{
	char	buff[4];

	while (1)
	{
		readsize = read(fd, buff, 1);
		buff[readsize] = '\0';
		if (readsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buff);
		else
			sline = ft_strjoin(sline, buff);
		if (ft_strchr(buff, '\n') || readsize == 0)
			break ;
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	long		index;
	long		readsize;
	static char	*sline;
	char		*line;
	char		*tmp;

	readsize = 1;
	if (readsize == 0)
		return (NULL);
	sline = mywhile(fd, readsize, sline);
	index = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	line = ft_substr(sline, 0, index);
	tmp = sline;
	sline = ft_substr(sline, index, ft_strlen(sline));
	free(tmp);
	return (line);
}
