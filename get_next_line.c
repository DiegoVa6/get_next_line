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

#include <unistd.h>
#define BUFF_SIZE 1024

void	new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != \n || str[i] != \0)
}

char	*get_next_line(int fd)
{
	ssize_t 	bytesr;
	char		*buffer;
	static char	*str;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesr = read(fd, buffer, BUFF_SIZE);
	if (bytesr < 0)
		return (NULL);
	ft_strjoin(str, buffer);
}

int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
