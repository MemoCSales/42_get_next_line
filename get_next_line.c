/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:02:37 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/01/15 17:57:09 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd == 1 || fd == 2)
	{
		free(backup);
		free(buffer);
		backup = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_from_file(fd, backup, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	backup = read_line(line);
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

// void	*ft_calloc(size_t count, size_t size)
// {
// 	unsigned char	*tmp;
// 	size_t			i;

// 	tmp = malloc(count * size);
// 	i = 0;
// 	if (!(tmp))
// 		return (NULL);
// 	while (i < size * count)
// 	{
// 		tmp[i] = 0;
// 		i++;
// 	}
// 	return (tmp);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	char	ch;
// 	int		i;

// 	i = 0;
// 	ch = (char) c;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == ch)
// 			return ((char *) &s[i]);
// 		i++;
// 	}
// 	if (s[i] == ch)
// 		return ((char *) &s[i]);
// 	return (NULL);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*news;
// 	ssize_t	i;
// 	ssize_t	j;

// 	if (s1 == NULL)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (s1 == NULL || s2 == NULL)
// 		return (0);
// 	news = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
// 	if (!(news))
// 		return (0);
// 	i = -1;
// 	j = 0;
// 	if (s1)
// 		while (s1[++i] != '\0')
// 			news[i] = s1[i];
// 	while (s2[j] != '\0')
// 		news[i++] = s2[j++];
// 	news[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free((void *)(s1));
// 	return (news);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	slen;
// 	size_t	i;
// 	char	*subs;

// 	i = 0;
// 	slen = ft_strlen(s);
// 	if (start >= slen)
// 		len = 0;
// 	if (len > start + slen)
// 		len = start + slen;
// 	subs = (char *) malloc((len + 1) * sizeof(char));
// 	if (!(subs))
// 		return (0);
// 	while (i < len && s[start + i] != '\0')
// 	{
// 		subs[i] = s[start + i];
// 		i++;
// 	}
// 	subs[i] = '\0';
// 	return (subs);
// }

// int main(void)
// {
// 	int 	fd;
// 	// int 	fd_2;
// 	// int 	fd_3;
// 	char 	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open file\n");
// 		return (1);
// 	}
// 	// fd_2 = open("text_2.txt", O_RDONLY);
// 	// if (fd == -1)
// 	// {
// 	// 	printf("Failed to open file\n");
// 	// 	return (1);
// 	// }
// 	// fd_3 = open("text_3.txt", O_RDONLY);
// 	// if (fd == -1)
// 	// {
// 	// 	printf("Failed to open file\n");
// 	// 	return (1);
// 	// }
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 	    printf("%s", line);
// 	    free(line);
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd_2);
// 	// printf("%s", line);
// 	// line = get_next_line(fd_3);
// 	// printf("%s", line);
	
// 	close(fd);
// 	// close(fd_2);
// 	// close(fd_3);
// 	return (0);
// }
