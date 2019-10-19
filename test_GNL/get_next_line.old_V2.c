/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:58:23 by florian           #+#    #+#             */
/*   Updated: 2018/12/13 17:02:42 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_debug.h"

static char	*ft_join(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (s1 || s2)
	{
		size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		if (!(str = (char *)malloc(size + 1)))
			return (NULL);
		while (s1 && *s1)
			str[i++] = *s1++;
		while (s2 && *s2)
			str[i++] = *s2++;
		str[i] = '\0';
	}
	return (str);
}

static int	ft_read(int fd, char **s)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	while ((bytes_read = read(fd, &buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (*s)
		{
			tmp = *s;
			*s = ft_join(*s, buffer);
			if (tmp)
				free(tmp);
		}
		else
			*s = ft_strdup(buffer);
	}
	return (bytes_read);
}

int			get_next_line(const int fd, char **line)
{
	static char *s = NULL;
	char		*tmp;
	int			ret;

	ret = 1;
	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!s)
		ret = ft_read(fd, &s);
	if (ret < 0)
		return (-1);
	if (!s)
		return (0);
	tmp = s;
	*line = ft_strsub(s, 0, ft_strclen(s, '\n'));
	s = ft_strsub(s, ft_strclen(s, '\n') + 1, ft_strlen(s) - ft_strclen(s, '\n'));
	if (s[0] == '\0')
	{
		free(s);
		s = NULL;
	}
	if (tmp)
		free(tmp);
	return (1);
}

#include <stdio.h>
int				main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	gnl_ret = get_next_line(p[0], &line);
	printf("%s", line);
//	mt_assert(gnl_ret == 1);
//	mt_assert(strcmp(line, "abc") == 0);

	gnl_ret = get_next_line(p[0], &line);
	printf("%s", line);
//	mt_assert(gnl_ret == 1);
//	mt_assert(line == NULL || *line == '\0');

	gnl_ret = get_next_line(p[0], &line);
	printf("%s", line);
//	mt_assert(gnl_ret == 0);
//	mt_assert(line == NULL || *line == '\0');

	gnl_ret = get_next_line(p[0], &line);
	printf("%s", line);
	printf("%d", get_next_line(fd, &line));
//	mt_assert(gnl_ret == 0);
//	mt_assert(line == NULL || *line == '\0');
}
