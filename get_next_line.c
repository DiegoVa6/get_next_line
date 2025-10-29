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
	i = 0;
	while (str[i] != '\n')
                {
                        line[i] = str[i];
                        i++;
                }
	line[i] = '\n';
	line[i + 1] = '\0';
}

char	*new_line(char *str)
{
	int	i;
	char	*chr;
	char	*line;

	i = 0;
	chr = ft_strchr(str, '\n');
	if (chr)
		line = ft_line(str);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t 	bytesr;
	char		*buffer;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1);
		if (!str)
			return NULL;
		str[0] = '\0';
	}
	while (!ft_strchr(str, '\n'))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytesr = read(fd, buffer, BUFFER_SIZE);
		if (bytesr <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesr] = '\0';
		str = ft_strappend(str, buffer);
		free(buffer);
	}
	return(new_line(str));
}

int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
