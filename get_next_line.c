/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omputle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:56:21 by omputle           #+#    #+#             */
/*   Updated: 2019/07/05 15:06:02 by omputle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strmerge(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

static	char	*read_line(int fd, char *s)
{
	int		num;
	char	buff[BUFF_SIZE + 1];

	while ((num = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[num] = '\0';
		s = ft_strmerge(s, buff);
		if (ft_strchr(s, '\n') != NULL)
			break ;
	}
	return (s);
}

static char		*new_line(char *s, char **line)
{
	char	*new;
	int		count;

	count = 0;
	while (s[count] != '\n' && s[count] != '\0')
		count++;
	*line = ft_strsub(s, 0, count);
	new = ft_strsub(s, count + 1, (ft_strlen(s + count + 1)));
	free(s);
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s;
	char		buff[BUFF_SIZE + 1];

	if (!(line) || fd < 0 || read(fd, buff, 0) == -1)
		return (-1);
	if (!s)
		s = ft_strnew(0);
	if (!(ft_strchr(s, '\n')))
		s = read_line(fd, s);
	if (ft_strlen(s) == 0)
		return (0);
	s = new_line(s, line);
	return (1);
}
