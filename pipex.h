#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>



typedef struct s_piplist{
	char **av;
	char **en;
	int ac;
	int p_fd[2];
	int in;
	int out;
	char **cmd1;
	char **cmd2;
	char *path;
	char *cmd;
}	t_piplist;

int ft_strlen(char *s);
char **ft_split(char const *s, char c);
char *ft_strjoin(char const *s1, char const *s2);
#endif
