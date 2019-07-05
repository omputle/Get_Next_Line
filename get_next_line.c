/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omputle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:56:21 by omputle           #+#    #+#             */
/*   Updated: 2019/07/05 23:20:40 by omputle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strmerge(char *prefix, char *suffix)
{
	char	*new;

	new = ft_strjoin(prefix, suffix);
	free(prefix);
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
	char	*temp;
	int		count;

	count = 0;
	while (s[count] != '\n' && s[count])
		count++;
	*line = ft_strsub(s, 0, count);
	temp = s + count + 1;
	new = ft_strsub(s, count + 1, (ft_strlen(temp)));
	free(s);
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[100];
	int			check;
	char		buff[BUFF_SIZE + 1];

	check = read(fd, buff, 0);
	if ((line == NULL) || fd < 0 || check == -1)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strnew(1);
	if (ft_strchr(s[fd], '\n') == NULL)
		s[fd] = read_line(fd, s[fd]);
	if (ft_strlen(s[fd]) == 0)
		return (0);
	s[fd] = new_line(s[fd], line);
	return (1);
}
