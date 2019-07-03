/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omputle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:56:21 by omputle           #+#    #+#             */
/*   Updated: 2019/07/03 17:27:37 by omputle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_strappend(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

static	char	*read_line(int fd, char *s)
{
	int		num;
	char	buff[BUFF_SIZE + 1];

	while ((num = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[num] = '\0';
		s = ft_strappend(s,  buff);
		if (ft_strchr(s, '\n') != NULL)
			break ;
	}
	return (s);
}

static char	*ft_this(char *s, char **line)
{
	char	*temp;
	int		count;

	count = 0;
	while (s[count] != '\n' && s[count] != '\0')
		count++;
	*line = ft_strsub(s, 0, count);
	if (ft_strcmp(*line, s) == 0)
		return (NULL);
	else
	{
		temp = ft_strsub(s, count + 1, (ft_strlen(s + count + 1)));
		free(s);
	}
	return (temp);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	int		num;
	char	buf[BUFF_SIZE + 1];

	if (!(*line) || fd < 0 || (read(fd, buf, 0) == -1))
		return (-1);
	if(!(s[fd]))
		s[fd] = ft_strnew(0);
	if (!(ft_strchr(s[fd], '\n')))
		s[fd] = read_line(fd, s[fd]);
	if (num == 0 && !(ft_strlen(s[fd])))
		return (0);
	s[fd] = ft_this(s[fd], line);
	return (1);
}
