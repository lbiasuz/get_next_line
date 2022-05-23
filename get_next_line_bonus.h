/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:07 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/21 22:44:45 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

size_t	ft_strlen(const char *s);
int		ft_strchr(char *src, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char **dest, char **src);
char	*get_next_line(int fd);

#endif