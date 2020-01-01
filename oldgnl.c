/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:55:42 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/11 15:53:23 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
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
static int		ft_cutline(char *s[], char **line, int fd)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		printf("WHAT ? \n");
		if (!(*line = ft_substr(s[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(s[fd] + len + 1)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(s[fd])))
			return (-1);
		if (s[fd] != NULL)
		{
			printf("LAST FREE !\n");
			free(s[fd]);
			s[fd][0] = '\0';
		}
	}
	return (1);
}

static char		*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < (ft_strlen(str) + 1))
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}

static int		ft_read(char *s[], int ret, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, &buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(s[fd], buf)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

void			*ft_memset(void *b, int c,  size_t len)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		s[i] = ch;
		i++;
	}
	return (s);

}

int				get_next_line(int fd, char **line)
{
	static char	*s[MAX_FD];
	size_t		len;
	int			ret;

	ret = 1;
	len = 0;
	if (line == NULL || fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (-1);
	if (s[fd] == NULL)
	{
		if (!(s[fd] = (char *)malloc(2)))
			return (-1);
		ft_memset(s[fd], '\0', 2);
	}
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		return (ft_cutline(s, line, fd));
	}
	else
	{
		printf("THE END ! \n");
		ret = ft_read(s, ret, fd);
		if (ret < 0)
			return (-1);
		printf("almost ! \n");
		if (ret == 0 && (s[fd][0] == '\0'))
		{
		printf("and i'm out ! LAST VALUES s[fd] : %s et ret : %d \n",s[fd], ret);
			return (0);
		}
	}
	printf("ret = %d \n", ret);
	return (ft_cutline(s, line, fd));
}