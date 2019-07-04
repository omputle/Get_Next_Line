
#include "get_next_line.h"
#include <stdlib.h>

int	get_next_line(int fd, char **line);

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ft_putendl(line);
			free(line);
		}
	}
	return (0);
}
