/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bod <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:56:39 by bod               #+#    #+#             */
/*   Updated: 2019/10/30 13:56:40 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int		main(int ac, char **av)
{
	int fd;
	char *str;
	int ret;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		while ((ret = get_next_line(fd, &str)) > 0)
		{
			printf("%s\n", str);
			free(str);
		}
		printf("ret %d\n", ret);
	}
	return (0);
}
