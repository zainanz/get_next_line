/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:35:10 by zali              #+#    #+#             */
/*   Updated: 2025/05/14 17:51:25 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			i;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	i = 0;
	line = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (extract_line(fd, &line, buffer[fd]))
		return (free(line), NULL);
	if (line)
	{
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i] == '\n')
			i++;
		line[i] = 0;
	}
	trim_buffer(buffer[fd]);
	return (line);
}
