/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:58:07 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 11:10:59 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = s1 ? ft_strlen((char *)s1) : 0;
	s2_len = s2 ? ft_strlen((char *)s2) : 0;
	if (!(result = malloc(sizeof(char) *
	(s1_len + s2_len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*ptr;

	if (!s || start < 0)
		return (0);
	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		len = 0;
	else
		len = slen - start < len ? slen - start : len;
	if (!(ptr = (char *)malloc(len + 1)))
		return (0);
	while (len)
	{
		ptr[i] = s[start];
		i++;
		start++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
