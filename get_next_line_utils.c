/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:05:37 by bedantas          #+#    #+#             */
/*   Updated: 2025/08/13 09:57:17 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (len == 0 || start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *rest, char const *buffer)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	len_i;
	size_t	len_j;

	i = 0;
	j = 0;
	len_i = ft_strlen(rest);
	len_j = ft_strlen(buffer);
	s3 = (char *)malloc(sizeof(char) * (len_i + len_j + 1));
	if (!s3)
		return (NULL);
	while (i < len_i)
	{
		s3[i] = rest[i];
		i++;
	}
	while (j < len_j)
	{
		s3[i + j] = buffer[j];
		j++;
	}
	s3[len_i + len_j] = '\0';
	return (s3);
}
