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

int ft_strlen(char *s);
char **parsing_split(char *s);
char **ft_split(char const *s, char c);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
#endif
