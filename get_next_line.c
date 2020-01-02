/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:02:58 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 11:20:01 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int  file_handler(char **file, char **line)
{
    int     i;
    int     ret;
    char    *tmp;
    i = 0;
    tmp = NULL;
    if (*file[i])
    {
        while ((*file)[i] != '\n' && (*file)[i])
            i++;
        ret = ((*file)[i] == '\n') ? 1 : 0;
        if (!(*line = ft_substr(*file, 0, i)))
            return (-1);
        if (ret == 1)
            if (!(tmp = ft_strdup(*file + (i + 1))))
                return (-1);
        free(*file);
        *file = tmp;
        return (ret);
    }
    free(*file);
    *file = NULL;
    if (!(*line = ft_strdup("")))
        return (-1);
    return (0);
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

static int  output(char **file, char **line, int ret)
{
    if (ret == -1)
        return (-1);
    if (ret == 0 && *file == NULL)
    {
        *line = ft_strdup("");
        return (0);
    }
    else
        return (file_handler(file, line));
}

int         get_next_line(int fd, char **line)
{
    static char *file = NULL;
    int         ret;
    char        *tmp;
    char        buf[BUFFER_SIZE + 1];
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (!(tmp = ft_strjoin(file, buf)))
            return (-1);
        free(file);
        file = tmp;
        if (ft_strchr(file, '\n'))
            break ;
    }
    return (output(&file, line, ret));
}
