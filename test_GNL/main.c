/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:26:02 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/09 15:14:52 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
