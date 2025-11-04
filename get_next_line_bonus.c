/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:02:11 by dvallada          #+#    #+#             */
/*   Updated: 2025/11/04 12:45:23 by dvallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *str)
{
	size_t	i;
	char	*line;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, str, i);
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_endline(char *str)
{
	int		i;
	char	*line;

	i = ft_strlen(str);
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, str, i);
	line[i] = '\0';
	return (line);
}

char	*new_line(char **str)
{
	char	*line;
	char	*chr;
	char	*rest;

	if (!*str || **str == '\0')
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	chr = ft_strchr(*str, '\n');
	if (!chr)
	{
		line = ft_endline(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	line = ft_line(*str);
	rest = NULL;
	if (chr[1] != '\0')
		rest = ft_strdup(chr + 1);
	free(*str);
	*str = rest;
	return (line);
}

static char	*buffer_str_free(char **str, char **buffer)
{
	free(*buffer);
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t		bytesr;
	char		*buffer;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str[fd] == NULL || !(ft_strchr(str[fd], '\n')))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		while (1)
		{
			bytesr = read(fd, buffer, BUFFER_SIZE);
			if (bytesr == -1)
				return (buffer_str_free(&str[fd], &buffer));
			buffer[bytesr] = '\0';
			str[fd] = ft_strappend(str[fd], buffer);
			if (ft_strchr(buffer, '\n') || bytesr == 0)
				break ;
		}
		free(buffer);
	}
	return (new_line(&str[fd]));
}
