/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:57:16 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/16 19:14:18 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char *find_path(char **path)
{
	while(*path)
	{
		if(ft_strnstr(*path, "PATH=", 5) != NULL)
			return (*path);
		path++;
	}
	return (NULL);
}

char  *check_exec(char *p, char **env)
{
	char *full_path = NULL;
	char *path = find_path(env);
	if (!path)
		return (NULL);
	char **path_cmd = ft_split(path + 5, ':');

	while(*path_cmd)
	{
		full_path = ft_strjoin(*path_cmd, "/");
		full_path = ft_strjoin(full_path, p);
		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		path_cmd++;
	}
	return (full_path);
}
void	ft_proc(t_piplist av)
{
	if (av.index != 2)
	{
		dup2(av.tmp_in, STDIN_FILENO);
	}
	if (av.index + 1 != av.ac - 1)
	{
		dup2(av.p_fd[1], 1);
		close(av.p_fd[1]);
	}
	else
	{
		dup2(av.out, 1);
		close(av.p_fd[1]);
	}
	// close(av.p_fd[0]);
	av.tmp[0] = check_exec(av.tmp[0], av.env);
	if (!av.tmp[0])
	{
		dprintf(2, "Commend NOt found\n");
		return ;
	}
	execve(av.tmp[0], av.tmp, av.env);
}

void execution_(t_piplist av)
{
	av.tmp_in = 0;

	while (av.index < av.ac - 1)
	{
		av.tmp = parsing_split(av.av[av.index]);
		if ((pipe(av.p_fd)) == -1 )
		{
			dprintf(2, "pipe deosn't work");
		}
		int pid = fork();
		if (pid == 0)
			ft_proc(av);
		else
		{
			av.tmp_in = av.p_fd[0];
			close(av.p_fd[1]);
		}
		av.index++;
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac >= 5)
	{
		t_piplist p_list;

		p_list.av = av;
		p_list.env = env;
		p_list.ac = ac;
		p_list.index = 2;

		p_list.in = open("file1", O_RDONLY);
		p_list.out = open("file2", O_CREAT | O_WRONLY | O_TRUNC , 0777);
		dup2(p_list.in, STDIN_FILENO);
		execution_(p_list);

		while ((waitpid(-1, NULL, 0)) > 0)
			;
		close(p_list.in);
		close(p_list.out);
		close(p_list.p_fd[0]);
		close(p_list.p_fd[1]);
		while(1) ;
	}
	else
		printf("the arg is not valid");
}
