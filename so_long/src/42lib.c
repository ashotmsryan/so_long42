/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42lib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:38:38 by amsryan           #+#    #+#             */
/*   Updated: 2022/06/08 16:18:07 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str)
		if (!str[0])
			return (0);
	if (!str)
		return (0);
	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t l)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (l > ft_strlen(s))
		l = ft_strlen(s);
	ptr = (char *)malloc((l + 1));
	if (!ptr)
		return(0);
	if (l == 0 || ft_strlen(s) < l || ft_strlen(s) < start)
	{
		ptr[i] = '\0';
		return(ptr);
	}
	while(s && s[start] && i < l)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*a;

	i = ft_strlen(s);
	a = malloc((i + 1) * sizeof(char));
	i = 0;
	if (!a)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	s[i] = '\0';
	return (s);
}


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

void	ft_putnbr(int nb)
{
	int	i;
	int	j;

	if (nb < 0)
	{
		write(1, "-", 1);
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
	char a = (char)j;
	write(1, &a, 1);
}

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

void	valid_flood_fill_map(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
			{
				free_double(&map);
				clean_and_exit(data, 1, "Invalid map\n");
			}
			j++;
		}
		i++;
	}
}


void	fill(char **str, int x, int y, char to_fill)
{
	if (x < 0 || y < 0 || (str[y][x] != 'C' && str[y][x] != 'E'
		&& str[y][x] != '0' && str[y][x] != to_fill))
		return ;
	str[y][x] = '-';
	fill(str, x - 1, y, to_fill);
	fill(str, x + 1, y, to_fill);
	fill(str, x, y - 1, to_fill);
	fill(str, x, y + 1, to_fill);
}
