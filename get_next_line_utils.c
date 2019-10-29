/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:58:07 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/29 16:27:35 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	if (!s1 || !s2)
		return (0);
	if (!(tab = (char *)malloc(sizeof(char) *
		((ft_strlen(s1) + ft_strlen((char const *)s2)) + 1))))
		return (0);
	while (s1[i])
		tab[count++] = s1[i++];
	while (s2[j])
		tab[count++] = s2[j++];
	tab[count] = '\0';
	return (tab);
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
	int		len;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
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
