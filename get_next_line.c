/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:02:11 by dvallada          #+#    #+#             */
/*   Updated: 2025/10/25 18:43:55 by dvallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (**str == '\0')
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

char *get_next_line(int fd)
{
	ssize_t bytesr;
	char *buffer;
	static char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL || !(ft_strchr(str, '\n')))
	{
		while (1)
		{
			buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!buffer)
				return (NULL);
			bytesr = read(fd, buffer, BUFFER_SIZE);
			if (bytesr == -1)
			{
				free(buffer);
				return (NULL);
			}
			buffer[bytesr] = '\0';
			str = ft_strappend(str, buffer);
			if (ft_strchr(buffer, '\n'))
			{
				free(buffer);
				break ;
			}
			free(buffer);
			if (bytesr == 0)
				break ;
		}
	}
	return (new_line(&str));
}
