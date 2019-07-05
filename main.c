/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omputle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:02:21 by omputle           #+#    #+#             */
/*   Updated: 2019/07/05 21:14:32 by omputle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (ac == 3)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		while (get_next_line(fd1, &line))
		{
			ft_putendl(line);
			free(line);
		}
		close(fd1);
		sleep(2);
		ft_putendl("\n \nThe second text begins now \n \n");
		sleep(2);
		while (get_next_line(fd2, &line))
		{
			ft_putendl(line);
			free(line);
		}
		close(fd2);
	}
	return (0);
}
