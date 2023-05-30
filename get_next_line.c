/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:41:14 by bmoudach          #+#    #+#             */
/*   Updated: 2023/05/30 16:42:14 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*buff;
	int		i;

	i = 0;
	buff = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!buff)
		return (0);
	while (src[i] != '\0')
	{
		buff[i] = src[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

void	ft_mouv(char *buf)
{
	int	i;
	int	j;

	i = ft_strchr(buf, '\n') - buf + 1;
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			byte;

	byte = 0;
	if (fd <= 0)
		return (NULL);
	line = ft_strdup(buf);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte <= 0)
			return (free(line), NULL);
		buf[byte] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
	}
	line[ft_strchr(line, '\n') - line + 1] = '\0';
	ft_mouv(buf);
	return (line);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("texte", O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (!str)
			return (0);
		write(1, str, ft_strlen(str));
		free(str);
	}
	close(fd);
}
