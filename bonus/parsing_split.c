/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:43:18 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/19 18:33:15 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char *free_all(char **buff, int j)
{
	while (j >= 0)
	{
		free(buff[j]);
		buff[j] = NULL;
		j--;
	}
	free(buff);
	return NULL;
}
int count(char *s, char p)
{
	int i = 0;
	char *c = "\'";
	while(*s)
	{
		while(*s && *s == p)
			s++;
		if (!s)
			break;
		if (*s && *s == *c)
		{
			s++;
			while(*s && *s != *c)
				s++;
			s++;
		}
		while(*s && !(*s == p || *s == *c))
			s++;
		while(*s && *s == p)
			s++;
		if (!s)
			break;
		i++;
	}
	return (i);
}
void	skip(char **s, int *len, char p, char **start)
{
	char *end;
	char quote;

	quote = '\'';
	while(**s && **s == p)
		(*s)++;
	if (!*s)
		return ;
	*start = *s;
	if (**s && **s == quote)
	{
		(*s)++;
		*start = *s;
		while (**s && **s != quote)
			(*s)++;
		end = *s;
		(*s)++;
	}
	else
	{
		while(**s && !(**s == p))
			(*s)++;
		end = *s;
	}
	*len = end - *start;
}
void	edit(int len, int j, char *start,char **buff)
{
	int i;

	i = 0;
	while( i < len)
		{
			buff[j][i++] = *start++;
		}
	buff[j][i] = '\0';
}
char **parsing_split(char *s, char p)
{
	char **buff;
	char *start, *end;
	int wc;
	int len;
	int j;

	if (!s)
		return NULL;
	wc = count(s, p);
	len = 0;
	if (!(buff = malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	len = 0;
	j = 0;
	while(j < wc)
	{
		skip(&s, &len, p, &start);
		buff[j] = malloc(len + 1);
		if (!buff[j])
			return (free_all(buff, j), NULL );
		edit(len, j, start, buff);
		j++;
	}
	buff[j] = NULL;
	return buff;
}

