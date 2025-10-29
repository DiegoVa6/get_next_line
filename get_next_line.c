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
	int	i;
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
	str = NULL;
	return (line);
}

char	*new_line(char *str)
{
	char	*line;
	char	*chr;

	if (str[0] == '\0')
		return (NULL);
	chr = ft_strchr(str, '\n');
	if (chr)
	{
		line = ft_line(str);
		str = chr;
	}
	else
		line = ft_endline(str);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t 	bytesr;
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
			return(new_line(str));
	}
	return(new_line(str));
}
