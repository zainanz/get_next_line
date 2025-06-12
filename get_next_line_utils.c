/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:38:16 by zali              #+#    #+#             */
/*   Updated: 2025/05/14 17:52:38 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (free(s1), NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

void	trim_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

int	extract_line(int fd, char **line, char *buffer)
{
	int	bytes_read;

	bytes_read = 0;
	if (*buffer)
		*line = ft_strjoin_and_free(*line, buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
			buffer[0] = '\0';
		if (bytes_read == -1)
			return (1);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*line = ft_strjoin_and_free(*line, buffer);
	}
	return (0);
}
