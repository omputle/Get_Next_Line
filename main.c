#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include "libft/libft.h"

int		main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("check.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}


/*int		main(void)
{
	ft_putnbr(ft_strlen("Orapeleng"));
	return (0);
}
*/
