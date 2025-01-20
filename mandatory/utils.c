#include "pipex.h"

void	free_all(char **bf,int j)
{
	while(j >= 0)
	{
		free(bf[j]);
		bf[j] = NULL;
		j--;
	}
	free(bf);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t ls1;
    size_t ls2;
    size_t i;
    size_t k;
	char *p;

    ls1 = ft_strlen((char *)s1);
    ls2 = ft_strlen((char *)s2);
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

size_t ft_strlen(char *s)
{
	size_t i;

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
