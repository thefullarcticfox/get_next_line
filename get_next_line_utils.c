#include "get_next_line.h"

char			*ft_strchr_nl(const char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char*)s);
		s++;
	}
	return (NULL);
}

char			*ft_strdup_nl(const char *s1)
{
	char	*strcp;
	size_t	size;

	size = 0;
	while (*(s1 + size) != '\0')
		size++;
	if (!(strcp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (*s1 != '\0')
		*strcp++ = *s1++;
	*strcp = '\0';
	return (strcp - size);
}

static size_t	ft_strlen_nl(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0' && *(s + len) != '\n')
		len++;
	return (len);
}

char			*ft_strjoin_nl(char *s1, char *s2, int canfree)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen_nl(s1);
	len2 = ft_strlen_nl(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (*s1 != '\0' && *s1 != '\n')
		*str++ = *s1++;
	if (canfree)
		free(s1 - len1);
	while (*s2 != '\0' && *s2 != '\n')
		*str++ = *s2++;
	*str = '\0';
	return (str - len1 - len2);
}
