#include "pipex.h"

int count(char *s)
{
	int i = 0;
	char *c = "\'";
	while(*s)
	{
		while(*s && *s == ' ')
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
		while(*s && !(*s == ' ' || *s == *c))
			s++;
		while(*s && *s == ' ')
			s++;
		if (!s)
			break;
		i++;
	}
	return (i);
}


char **parsing_split(char *s)
{

	int i;
	char *c = "\'";
	if (!s)
		return NULL;
	int wc = count(s);

	char **buff;
	buff = malloc((wc + 1) * sizeof(char *));
	if (!buff)
		return (NULL);
	char *start, *end;
	int len = 0;
	int j = 0;
	while(j < wc)
	{
		while(*s && *s == ' ')
			s++;
		if (!s)
			break;
		start = s;
		if (*s && *s == *c)
		{
			s++;
			start = s;
			while (*s && *s != *c)
				s++;
			end = s;
			s++;
		}
		else
		{
			while(*s && !(*s == ' '))
				s++;
			end = s;
		}
		len = end - start;
		buff[j] = malloc(len + 1);
		if (!buff[j])
			return NULL;
		i = 0;
		while( i < len)
			buff[j][i++] = *start++;
		buff[j][i] = '\0';
		j++;

	}
	buff[j] = NULL;

	return buff;

}

