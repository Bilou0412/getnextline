/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:41:14 by bmoudach          #+#    #+#             */
/*   Updated: 2023/05/27 14:59:32 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash = "\0";
	char			*line;
	char			*buf;
	int				size;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		if (0 > read(fd, buf, BUFFER_SIZE))
			return (NULL);
		stash = ft_strjoin(stash, buf);
	}
	size = ft_strchr(stash, '\n') - stash;
	line = malloc((size + 3) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, size + 2);
	stash = ft_strchr(stash, '\n') + 1;
	return (line);
}

int	main(void)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("texte", O_RDONLY);
	while (i++ < 11)
	{
		str = get_next_line(fd);
		write(1, str, ft_strlen(str));
	}
	close(fd);
}
