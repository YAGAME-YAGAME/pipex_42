/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:40:31 by yagame            #+#    #+#             */
/*   Updated: 2025/01/19 22:04:33 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
int ft_strcmp(char *s1, char *s2)
{
	while(*s1 || *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	init_list(t_piplist *p, char **av, char **env, int ac)
{
	p->av = av;
	p->env = env;
	p->ac = ac;
	p->index = 2;
	p->in = -1;
	p->out = -1;
	p->herdoc = false;
}
void	init_herdoc(t_piplist *p)
{
	p->index = 3;
	p->herdoc = true;
}
bool check_herdoc(char *av)
{
	char *her = "here_doc";
	if (ft_strcmp(her, av) == 0)
		return (true);
	return (false);
}

void	here_doc(t_piplist p)
{
	char *buff;
	int fd;

	fd = open("/tmp/.here_doc", O_RDONLY | O_CREAT | O_APPEND , 0777);
	if (fd == -1)
		ft_error("open", 0);
	while(1)
	{
		ft_putstr_fd("here_doc> " , 1);
		buff = get_next_line(0);
		if (ft_strcmp(buff, p.av[2]))
			break;
		ft_putstr(buff, fd);
		free(buff);
	}
	free(buff);
	close(fd);
	p.out = open("/tmp/.here_doc" , O_RDONLY);
	if (p.out == -1)
	{
		inlink("/tmp/.here_doc");
		ft_error("Error opening here_doc file", 0);
	}
	unlink("/tmp/.here_doc");

}
