/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:55:42 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/18 15:28:57 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_cutline(char *s[fd], char **line)
{
	size_t len;
	char *tmp;

	while (s[fd][len] != '\n')
		len++;
	if (!())
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(s[fd] + len + 1)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(s[fd])))
			return (0);
	}
	return (1);
}

static int		ft_read(char *s[fd], char **line)
{
	int ret;
	char buf[BUFF_SIZE];

	ret = 1;
	while (ret = read(fd, &buf[BUFF_SIZE], BUFF_SIZE))
	{

	}
}

int				get_next_line(int fd, char **line)
{
	static char *s[fd];
	size_t		len;
	
	if (!(*line) || fd < 0)
		return (-1);
	if (!(s = (char *)malloc(1)))
		return (-1);
	while (s[fd][len] != '\0' || s[fd][len] != '\n')
		len++;
	if (s[fd][len] == '\n')
		return (ft_cutline(fd, line));
	else
	{
		ft_read(*s[fd])
	}
}
