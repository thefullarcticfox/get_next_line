#include "get_next_line.h"

static void	ft_cleanlastbuf(char **lastbuf)
{
	if (lastbuf == NULL)
		return ;
	free(*lastbuf);
	*lastbuf = NULL;
}

static int	ft_lastbufcheck(char **line, char **lastbuf)
{
	char	*temp;

	if (*lastbuf != NULL && **lastbuf != '\0')
	{
		if (!(*line = ft_strjoin_nl("", *lastbuf, 0)))
			return (-1);
		if (ft_strchr_nl(*lastbuf))
		{
			temp = *lastbuf;
			*lastbuf = ft_strdup_nl(ft_strchr_nl(*lastbuf) + 1);
			free(temp);
			if (*lastbuf == NULL)
				return (-1);
			return (1);
		}
		else
			ft_cleanlastbuf(lastbuf);
	}
	return (2);
}

static int	ft_readlines(char **line, int fd, char **lastbuf)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		rdres;
	char		*temp;

	while ((rdres = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[rdres] = '\0';
		if (*line == NULL)
			if (!(*line = ft_strdup_nl("")))
				return (-1);
		if (!(*line = ft_strjoin_nl(*line, buf, 1)))
			return (-1);
		if (ft_strchr_nl(buf))
		{
			temp = *lastbuf;
			*lastbuf = ft_strdup_nl(ft_strchr_nl(buf) + 1);
			free(temp);
			if (*lastbuf == NULL)
				return (-1);
			return (1);
		}
		if (rdres == 0)
			return (0);
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char		*lastbuf[15000];
	int				bufcheckres;
	int				rdres;

	if (fd < 0 || fd > 14999 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	*line = NULL;
	bufcheckres = ft_lastbufcheck(&(*line), &lastbuf[fd]);
	if (bufcheckres != 2)
		return (bufcheckres);
	rdres = ft_readlines(&(*line), fd, &lastbuf[fd]);
	if (rdres <= 0)
		ft_cleanlastbuf(&lastbuf[fd]);
	return (rdres);
}
