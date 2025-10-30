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
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_endline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\0')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*gnl_take_until_nl(char **str, char *nl)
{
	char	*line;
	char	*rest;

	line = ft_line(*str);
	if (nl[1] != '\0')
		rest = ft_strdup(nl + 1);
	else
		rest = NULL;
	free(*str);
	*str = rest;
	return (line);
}

char	*new_line(char **str)
{
	char	*line;
	char	*chr;

	if (!str || !*str || (**str == '\0'))
	{
		if (str && *str)
		{
			free(*str);
			*str = NULL;
		}
		return (NULL);
	}
	chr = ft_strchr(*str, '\n');
	if (chr)
		return (gnl_take_until_nl(str, chr));
	line = ft_endline(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		bytesr;
	char		*buffer;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (str == NULL || !(ft_strchr(str, '\n')))
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
		free(buffer);
		if (bytesr == 0)
			break ;
	}
	return (new_line(&str));
}
