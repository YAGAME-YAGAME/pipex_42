/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:43:07 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/20 17:39:12 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_piplist{
	char **av;
	char **env;
	char **tmp;
	int ac;
	int index;
	int p_fd[2];
	int in;
	int out;
	int tmp_in;
	char *path;
	char *cmd;
}	t_piplist;

size_t	ft_strlen(char *s);
int count(char *s, char p);
void 	free_all(char **bf, int j);
void	ft_error(char *message, int exit_code);
char **parsing_split(char *s, char p);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
#endif
