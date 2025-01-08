/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:57:16 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/08 16:37:12 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (NULL);
	while (haystack[i] && (len - i) >= ft_strlen((char *)needle))
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

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

void execution_(t_piplist av)
{
	int i = 0;
	int size = av.ac - 3;
	char **tmp;
	int tmp_in = 0;

	while (i < size)
	{
		tmp = ft_split(av.av[i + 2], ' ');
		pipe(av.p_fd);
		int pid = fork();
		if (pid == 0)
		{
			if (i != 0)
				dup2(tmp_in, STDIN_FILENO);
			if (i + 1 != size)
				dup2(av.p_fd[1], 1);
			else
				dup2(av.out, 1);
			close(av.p_fd[0]);
			tmp[0] = check_exec(tmp[0], av.env);
			if (!tmp[0])
			{
				dprintf(2, "Commend NOt found\n");
				return ;
			}
			execve(tmp[0], tmp, av.env);
		}
		else
		{
			tmp_in = av.p_fd[0];
			close(av.p_fd[1]);
			i++;
		}
	}
	while ((waitpid(-1, NULL, 0)) > 0)
	;
}

int	main(int ac, char **av, char **env)
{
	if (ac >= 5)
	{
		t_piplist p_list;

		p_list.av = av;
		p_list.env = env;
		p_list.ac = ac;

		p_list.in = open("file1", O_RDONLY);
		p_list.out = open("file2", O_CREAT | O_WRONLY | O_TRUNC , 0777);

		dup2(p_list.in, STDIN_FILENO);
		execution_(p_list);
		// while (1);

	}
	else
		printf("the arg is not valid");
}
