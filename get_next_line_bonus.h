/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:49:32 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/01/15 18:04:32 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define FD_SIZE 10240
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fc);
char	*read_from_file(int fd, char *buffer, char *backup);
char	*read_line(char *full_line);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif