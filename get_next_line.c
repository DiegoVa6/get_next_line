/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:02:11 by dvallada          #+#    #+#             */
/*   Updated: 2025/10/25 17:38:04 by dvallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFF_SIZE 1024

char	*get_next_line(int fd)
{
	ssize_t 	bytesr;
	char		*buffer;
	static char	*str;

	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1);
	if (fd < 0)
		return (NULL);
	bytesr = read(fd, buffer, BUFF_SIZE);
}

int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
