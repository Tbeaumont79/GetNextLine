/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:15:47 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/20 15:23:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRE  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"

int		get_next_line(int const fd, char **line);

int        main(int ac, char **av)
{
	int        	fd1;
	int        	fd2;
	int        	fd3;
	char    	*str;
	int        	ret1 = 1;
	int        	ret2 = 0;
	int        	ret3 = 0;
	int        	i;
	int			error;

	i = 1;
	fd1 = 0;
	fd2 = 0;
	fd3 = 0;
	error = 0;
	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		while ((ret1 = get_next_line(fd1, &str)) > 0)
		{
			printf(MAG"line %d "GRE"file 1 : %s\n", i, str);
			free(str);
		}
		i++;
		close(fd1);
	}
	else if (ac == 4 && BUFF_SIZE > 0)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		while (ret1 || ret2 || ret3)
		{ 
			if ((ret1 = get_next_line(fd1, &str)) > 0)
				printf(MAG"line %d "GRE"file 1 : %s\n", i, str);
			free(str);
			if ((ret2 = get_next_line(fd2, &str)) > 0)
				printf(MAG"line %d "YEL"file 2 : %s\n", i, str);
			free(str);
			if ((ret3 = get_next_line(fd3, &str)) > 0)
				printf(MAG"line %d "BLU"file 3 : %s\n", i, str);
			free(str);
			i++;
		}
		printf(BLU"\nNumber of lines reads:"GRE" %d \t\t\t\t\t 👌🏻", i * 3);
		close(fd1);
		close(fd2);
		close(fd3);
	}
	else
	{
		printf(RED"Error, number of arguments or BUFF_SIZE!\t\t\t ❌  \n");
		error = 1;
	}
	if (!error)
	{
		if (ret1 == 0 && ret2 == 0 && ret3 == 0)
			printf(NRM"\nLecture finie:\t\t\t\t ✅ \n");
		else
			printf(RED"Error, < read error > \t\t\t ❌  \n");
	}
	return (0);
}
