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
	static char	*sline[1024];
	char		*line;
	char		*tmp;

	readsize = 1;
	if (readsize == 0)
		return (NULL);
	sline[fd] = mywhile(fd, readsize, sline[fd]);
	index = ft_strlen(sline[fd]) - ft_strlen(ft_strchr(sline[fd], '\n')) + 1;
	line = ft_substr(sline[fd], 0, index);
	tmp = sline[fd];
	sline[fd] = ft_substr(sline[fd], index, ft_strlen(sline[fd]));
	free(tmp);
	return (line);
}
