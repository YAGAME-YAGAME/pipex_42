/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:06:46 by otzarwal          #+#    #+#             */
/*   Updated: 2025/01/05 14:06:57 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

static int	count_word(const char *str, char sep)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != sep && str[i])
			i++;
		c++;
	}
	return (c);
}

static char	**alloc_free(char **bf, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		free(bf[i]);
		bf[i] = NULL;
		i++;
	}
	free(bf);
	return (NULL);
}

static int	skip(char *s, int *index, char sep)
{
	int	start;
	int	i;

	i = *index;
	start = 0;
	while (s[i] && s[i] == sep)
		i++;
	start = i;
	while (s[i] && s[i] != sep)
		i++;
	*index = i;
	return (start);
}

static void	*ft_alloc(char **buff, char *s, int wc, char c)
{
	int	j;
	int	i;
	int	start;
	int	k;

	i = 0;
	start = 0;
	j = 0;
	while (j < wc)
	{
		start = skip(s, &i, c);
		k = 0;
		if (buff)
			buff[j] = malloc((i - start) + 1);
		if (!buff[j])
			return (alloc_free(buff, j));
		while (start < i)
			buff[j][k++] = s[start++];
		buff[j][k] = '\0';
		j++;
	}
	buff[j] = NULL;
	return (buff);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**buff;

	if (!s)
		return (NULL);
	wc = count_word(s, c);
	buff = malloc((wc + 1) * sizeof(char *));
	if (!buff)
	{
		return (NULL);
	}
	return (ft_alloc(buff, (char *)s, wc, c));
}
