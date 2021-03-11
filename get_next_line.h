#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr_nl(const char *s);
char	*ft_strdup_nl(const char *s1);
char	*ft_strjoin_nl(char *s1, char *s2, int canfree);

#endif
