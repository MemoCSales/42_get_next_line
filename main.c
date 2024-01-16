/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:51:25 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/01/15 18:07:21 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int 	fd;
	int 	fd_2;
	// int 	fd_3;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file\n");
		return (1);
	}
	fd_2 = open("text_2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file\n");
		return (1);
	}
	// fd_3 = open("text_3.txt", O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf("Failed to open file\n");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)) != NULL)
	// {
	//     printf("%s", line);
	//     free(line);
	// }
	line = get_next_line(fd);
	printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd_2);
	printf("%s", line);
	line = get_next_line(fd_2);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	
	close(fd);
	close(fd_2);
	// close(fd_3);
	return (0);
}
