/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:50:03 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/01/12 20:18:34 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*backup[FD_SIZE];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd == 1 || fd == 2)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_from_file(fd, backup[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	backup[fd] = read_line(line);
	return (line);
}

char	*read_from_file(int fd, char *backup, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(backup), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_calloc(1, sizeof(char));
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*read_line(char *full_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_line)
		return (free(full_line), NULL);
	while (full_line[i] != '\n' && full_line[i])
		i++;
	if (full_line[i] == 0 || full_line[1] == 0)
		return (NULL);
	line = ft_substr(full_line, i + 1, ft_strlen(full_line) - i);
	if (*line == 0)
		return (free(line), NULL);
	full_line[i + 1] = '\0';
	return (line);
}
