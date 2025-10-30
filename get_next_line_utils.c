/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:02:30 by dvallada          #+#    #+#             */
/*   Updated: 2025/10/25 17:20:49 by dvallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s != '\0')
	{
		c++;
		s++;
	}
	return (c);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (n > 0)
	{
		*b = *a;
		b++;
		a++;
		n--;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	t;

	t = (unsigned char) c;
	while (*s)
	{
		if ((unsigned char) *s == t)
			return ((char *)s);
		s++;
	}
	if (t == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strappend(char *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	if (!s2)
		return (s1);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2[0] == '\0')
		return (s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(l1 + l2 + 1);
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	free(s1);
	return (str);
}
