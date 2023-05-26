/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:46:52 by bmoudach          #+#    #+#             */
/*   Updated: 2023/05/26 16:18:30 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < n)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < n - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < n)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)src;
	i = 0;
	while (i < size - 1 && str[i] != '\0' && size > 1)
	{
		dst[i] = str[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			len;
	int			len_s1;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len + 1);
	str[len] = '\0';
	return (str);
}
