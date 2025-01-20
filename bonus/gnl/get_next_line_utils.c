/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:01:16 by otzarwal          #+#    #+#             */
/*   Updated: 2024/12/09 18:23:49 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strdup(const char *s1)
// {
// 	char	*buff;
// 	size_t	size;
// 	int		i;

// 	i = 0;
// 	if (!s1)
// 		return (NULL);
// 	size = ft_strlen(s1);
// 	buff = malloc(size + 1);
// 	if (!buff)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		buff[i] = s1[i];
// 		i++;
// 	}
// 	buff[i] = '\0';
// 	return (buff);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*new_str;
// 	size_t	total_len;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	new_str = (char *)malloc(total_len * sizeof(char));
// 	if (!new_str)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	i = -1;
// 	while (s1[++i])
// 		new_str[i] = s1[i];
// 	j = -1;
// 	while (s2[++j])
// 		new_str[i++] = s2[j];
// 	new_str[i] = '\0';
// 	free(s1);
// 	return (new_str);
// }

// int	ft_strchr(char *s, char c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return (1);
// 		s++;
// 	}
// 	return (0);
// }

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*buff;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		len = 0;
// 		start = 0;
// 		return (NULL);
// 	}
// 	if (start + len > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	buff = malloc(len + 1);
// 	if (!buff)
// 		return (NULL);
// 	while (s[start + i] && i < len)
// 	{
// 		buff[i] = s[start + i];
// 		i++;
// 	}
// 	buff[i] = '\0';
// 	return (buff);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }
#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		u;
	char	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	u = 0;
	while (s1[u])
	{
		ptr[u] = s1[u];
		u++;
	}
	ptr[u] = '\0';
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	if (!s)
		return (NULL);
	(len > ft_strlen(s) - start) && (len = ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


int ft_strchr(char *s, int c)
{
	size_t	u;

	u = 0;
	if (!s)
		return 0;
	while (u <= ft_strlen(s))
	{
		if (s[u] == (unsigned char)c)
			return (1);
		u++;
	}
	return (0);
}
size_t	ft_strlen(char const *s)
{
    size_t	counter;

    counter = 0;
    while (s[counter])
		counter++;
    return (counter);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    size_t ls1;
    size_t ls2;
    size_t i;
    size_t k;
	char *p;

    ls1 = ft_strlen(s1);
    ls2 = ft_strlen(s2);
    p = malloc(ls1 + ls2  + 1);
    if (!p)
        return (NULL);
    i  = 0;
    if (ls1)
        while (i < ls1)
        {
            p[i] = s1[i];
            i++;
        }
    k = 0;
    while (k <= ls2)
        p[i++] = s2[k++];
	// free((void *)s1);
    return (p);
}
