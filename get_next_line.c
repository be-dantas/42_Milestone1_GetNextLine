/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:52:34 by bedantas          #+#    #+#             */
/*   Updated: 2025/08/21 09:56:35 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char **rest, char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (NULL);
}

char	*buffer_for_rest(char *rest, int fd)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_all(&rest, &buffer));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(rest, buffer);
		if (!temp)
			return (free_all(&rest, &buffer));
		free(rest);
		rest = temp;
		if (ft_strchr(buffer, '\n') != -1)
			break ;
	}
	free(buffer);
	return (rest);
}

char	*new_line(char *rest, int n)
{
	if (n == -1)
		return (ft_strdup(rest));
	else
		return (ft_substr(rest, 0, (size_t)n + 1));
}

void	new_rest(char **rest, int n)
{
	char	*temp;

	if (!rest || !*rest)
		return ;
	if (n == -1 || (*rest)[n + 1] == '\0')
	{
		free(*rest);
		*rest = NULL;
		return ;
	}
	temp = ft_substr(*rest, n + 1, ft_strlen(*rest) - (size_t)n - 1);
	if (!temp)
	{
		free(*rest);
		*rest = NULL;
		return ;
	}
	free(*rest);
	*rest = temp;
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	rest = buffer_for_rest(rest, fd);
	if (!rest || *rest == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	n = ft_strchr(rest, '\n');
	line = new_line(rest, n);
	new_rest(&rest, n);
	return (line);
}
