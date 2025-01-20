/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:57:16 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/20 17:52:15 by yagame           ###   ########.fr       */
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
	char **path_cmd = parsing_split(path + 5, ':');

	while(*path_cmd)
	{
		full_path = ft_strjoin(*path_cmd, "/");
		full_path = ft_strjoin(full_path, p);
		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		full_path = NULL;
		path_cmd++;
	}
	free(p);
	return (full_path);
}
void	ft_proc(t_piplist av)
{
	if (av.index != 2)
	{
		dup2(av.tmp_in, STDIN_FILENO);
	}
	else
		dup2(av.in, STDIN_FILENO);
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
	av.tmp[0] = check_exec(av.tmp[0], av.env);
	if (!av.tmp[0])
		ft_error("Command not found", 0);
	execve(av.tmp[0], av.tmp, av.env);
}

void execution_(t_piplist av)
{
	av.tmp_in = 0;
	int status;
	pid_t pid;

	while (av.index < av.ac - 1)
	{
		av.tmp = parsing_split(av.av[av.index], ' ');
		if (!av.tmp)
			ft_error("split", 0);
		if ((pipe(av.p_fd)) == -1 )
			ft_error("pipe", 0);
		if ((pid = fork()) == -1)
			ft_error("fork", 0);
		if (pid == 0)
			ft_proc(av);
		else
		{
			close(av.p_fd[1]);
			if (av.tmp_in != -1)
				close(av.tmp_in);
			av.tmp_in = av.p_fd[0];
			if (av.index == av.ac - 2)
				close(av.tmp_in);
		}
		av.index++;
	}
	while (waitpid(pid, &status, 0) > 0) ;
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
		p_list.in = open(av[1], O_RDONLY);
		if (p_list.in == -1)
			ft_error(av[1], 0);
		p_list.out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC , 0777);
		if (p_list.in == -1)
			ft_error(av[ac - 1], 0);
		execution_(p_list);
		close(p_list.in);
		close(p_list.out);
	}
	else
		printf("the arg is not valid");
}
