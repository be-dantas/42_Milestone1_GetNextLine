/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:23:15 by bedantas          #+#    #+#             */
/*   Updated: 2025/08/11 18:39:15 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <unistd.h> // para write
# include <stdlib.h> // para malloc, free
# include <stddef.h> // para size_t

size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *resto, char const *buffer);

char	*get_next_line(int fd);

#endif