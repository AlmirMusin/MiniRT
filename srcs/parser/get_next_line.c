/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:33:21 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:30:22 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	re_writing(char **str1, char *str2)
{
	char *dont_kill_me_please;

	dont_kill_me_please = *str1;
	*str1 = ft_strjoin(*str1, str2);
	free(dont_kill_me_please);
}

int		writing(char **line, char **buf, int *line_found, char *iter)
{
	if (*iter == '\n')
	{
		*line_found = 1;
		*iter = '\0';
		re_writing(line, *buf);
		*buf = ft_strcpy(*buf, iter + 1);
		iter = NULL;
		if (!*line)
			return (-1);
		return (1);
	}
	else
	{
		re_writing(line, *buf);
		(*buf)[0] = '\0';
		if (*line == NULL)
		{
			*line_found = 1;
			return (-1);
		}
		return (0);
	}
}

int		split_txt(char **line, char *buf, int fd)
{
	int		line_found;
	int		buf_len;
	int		return_val;
	char	*iter;

	line_found = 0;
	buf_len = 0;
	iter = NULL;
	while (!line_found)
	{
		if (buf[0] == '\0')
		{
			if ((buf_len = read(fd, buf, BUFFER_SIZE)) <= 0)
				return (buf_len);
			buf[buf_len] = '\0';
		}
		iter = buf;
		while (*iter != '\n' && *iter != '\0')
			iter++;
		return_val = writing(line, &buf, &line_found, iter);
		iter = NULL;
	}
	return (return_val);
}

int		get_next_line(int fd, char **line)
{
	static char mass[1024][BUFFER_SIZE + 1];

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if ((*line = ft_strjoin("", "")) == NULL)
		return (-1);
	if (mass[fd] != NULL)
		return (split_txt(line, mass[fd], fd));
	mass[fd][0] = '\0';
	return (split_txt(line, mass[fd], fd));
}
