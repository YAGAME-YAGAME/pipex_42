/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:12:34 by otzarwal          #+#    #+#             */
/*   Updated: 2024/12/09 18:26:09 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 10
// # endif

// # include <stdlib.h>
// # include <unistd.h>
// # include <fcntl.h>

// char	*get_next_line(int fd);
// int		ft_strchr(char *s, char c);
// char	*ft_strdup(const char *s1);
// size_t	ft_strlen(const char *s);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_substr(char *s, unsigned int start, size_t len);

// #endif
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *s);
int 	ft_strchr(char *s, int c);
char	*bfnl(char *bf);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*afnl(char *bf);
int     ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
#endif
