/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:12:18 by ddemarco          #+#    #+#             */
/*   Updated: 2022/06/05 17:11:00 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*ft_read_fd(int fd, char *text)
{
	char	*buffer;
	int		writtenbytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!text)
		text = ft_calloc(1, 1);
	if (!text)
		return (NULL);
	writtenbytes = 1;
	while (writtenbytes > 0 && !ft_strrchr(buffer, '\n'))
	{
		writtenbytes = read(fd, buffer, BUFFER_SIZE);
		if (writtenbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[writtenbytes] = '\0';
		text = ft_append(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_nextline(char *buffer)
{
	char	*line;
	int		linelen;
	int		filelen;
	int		i;

	linelen = 0;
	filelen = ft_strlen(buffer);
	while (buffer[linelen] && buffer[linelen] != '\n')
		linelen++;
	if (!buffer[linelen])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((filelen - linelen + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++linelen])
		line[++i] = buffer[linelen];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD_NUM];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd]);
	buffer[fd] = ft_nextline(buffer[fd]);
	return (line);
}
