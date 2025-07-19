/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkelm <mkelm@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:13:29 by mkelm             #+#    #+#             */
/*   Updated: 2025/05/28 19:09:04 by mkelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;
	size_t	i;

	len = ft_strlen(s);
	buf = (char *)malloc(len + 1);
	if (!buf)
	{
		return (0);
	}
	i = 0;
	while (i <= len)
	{
		buf[i] = s[i];
		i++;
	}
	return (buf);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (char) c)
	{
		return ((char *)(s + i));
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char    *extract_line(char *saved)
{
    size_t  i;
    char    *line;
    size_t  j;

    i = 0;
    j = 0;
    if (!saved || saved[0] == '\0')
        return (NULL);
    while (saved[i] && saved[i] != '\n')
        i++;
    if (saved[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    while (j < i)
    {
        line[j] = line[i];
        j++;
    }
    line[i] = '\0';
    return (line);
}

char    *update_saved(char *saved)
{
    size_t  j;
    size_t  i;
    char    *new_saved;

    i = 0;
    j = 0;
    while(saved[i] && saved[i] != '\n')
        i++;
    if (!saved[i])
    {
        free(saved);
        return(NULL);
    }
    i++;
    new_saved = malloc(ft_strlen(saved + i) + 1);
    if (!new_saved)
        return (NULL);
    while (saved[i])
        new_saved[j++] = saved[i++];
    new_saved[j] = '\0';
    free(saved);
    return (new_saved);
}