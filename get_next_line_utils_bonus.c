/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:19:19 by abadidi           #+#    #+#             */
/*   Updated: 2020/02/16 16:19:34 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
    int i
    int j;
    i = -1;
    j = 0;

	dest = NULL;
	len = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(1 + ft_strlen(s1) + ft_strlen(s2));
	if (!dest)
		return (NULL);
    while (s1[++i])
        dest[i] = s1[i];
    while (s2[i])
        dest[i++] = s2[j++];
    dest[i]= 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	iter;

	if (!s)
		return (NULL);
	dest = NULL;
	if (start >= ft_strlen(s))
		len = 0;
	dest = malloc(1 + len * sizeof(char));
	if (!dest)
		return (NULL);
	iter = 0;
	while (iter < len && s[iter + start] != '\0')
	{
		dest[iter] = s[iter + start];
		iter++;
	}
	dest[iter] = '\0';
	return (dest);
}
