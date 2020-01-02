/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:55:42 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 11:14:27 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static int		ft_cutline(char *s[], char **line, int fd)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
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
		ret = ft_read(s, ret, fd);
		if (ret < 0)
			return (-1);
		if (ret == 0 && (s[fd][0] == '\0'))
			return (0);
	}
	return (ft_cutline(s, line, fd));
}
