/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:12:01 by abadidi           #+#    #+#             */
/*   Updated: 2020/02/17 22:35:39 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)src;
	while (s[i] != '\0')
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char *dest;
	char *s;

	dest = NULL;
	s = (char *)src;
	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (dest != NULL)
		ft_strcpy(dest, src);
	return (dest);
}

int		help1(int fd, char **rest)
{
	char	*tmp;
	int		ret;
	char	*BUFFER;

	BUFFER = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(*rest, '\n'))
	{
		ret = read(fd, BUFFER, BUFFER_SIZE);
		if (ret < 0)
		{
			free(BUFFER);
			return (-1);
		}
		BUFFER[ret] = '\0';
		tmp = *rest;
		*rest = ft_strjoin(*rest, BUFFER);
		free(tmp);
		if (ret == 0)
			break ;
	}
	free(BUFFER);
	return 1;
}

int		help2(char **line, char **rest)
{
	char *tmp;
	int len;
	char *f;

	if (ft_strchr(*rest, '\n'))
	{
		f = ft_strchr(*rest, '\n');
		len = f - *rest;
		*line = ft_substr(*rest, 0, len);
		tmp = *rest;
		*rest = ft_strdup(f + 1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
		return (0);
	}
	return 1;
}

int		get_next_line(int fd, char **line)
{
	static char *rest;
	if (!rest)
		rest = ft_strdup("");
	help1(fd, &rest);
	return help2(line, &rest);
}
