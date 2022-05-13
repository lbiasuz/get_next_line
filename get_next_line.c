/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:05 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/13 00:36:54 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gen_line(char **src)
{
	char	*nlp;
	char	*temp;
	
	nlp = ft_strchr(*src, '\n');
	if (nlp)
	{
		temp = ft_substr(*src, 0, nlp - *src + 1);
		*src = nlp + 1;
		return (temp);
	}
	return (*src);
}

char	*get_next_line(int fd)
{
	static char	*the_string;
	char		*line;
	// char		temp[BUFFER_SIZE + 1];
	// int			n_read;

	if (!the_string)
	{
		the_string = malloc(BUFFER_SIZE + 1);
		read(fd, the_string, BUFFER_SIZE);
		the_string[BUFFER_SIZE] = '\0';
	}
	line = gen_line(&the_string);
	// ft_strlcpy(the_string, ft_strchr(the_string, '\n', )
	return (line);
}
