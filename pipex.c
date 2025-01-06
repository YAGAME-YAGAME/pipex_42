/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:57:16 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/06 21:06:57 by otzarwal         ###   ########.fr       */
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

char  *check_exec(t_piplist *p)
{
	char *full_path = NULL;
	p->cmd1 = ft_split(p->av[2], ' ');
	p->cmd2 = ft_split(p->av[3], ' ');

	char *path = find_path(p->en) + 5;
	char **path_cmd = ft_split(path, ':');


	while(*path_cmd)
	{
		full_path = ft_strjoin(*path_cmd, "/");
		full_path = ft_strjoin(full_path, *p->cmd1);
		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		path_cmd++;
	}
	printf("%s\n", full_path);
	


	return (*path_cmd);
}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		t_piplist p_list;

		p_list.av = av;
		p_list.en = env;
		p_list.ac = ac;

		p_list.in = open("file1", O_RDONLY);
		p_list.out = open("file2", O_CREAT | O_WRONLY | O_TRUNC , 0777);

		check_exec(&p_list);


	}
	else
		printf("the arg is not valid");
}
