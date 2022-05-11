/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:05 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/10 23:56:13 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	const char	*the_string;
	char		*line;
	char		temp[BUFFER_SIZE];
	int			n_read;

	while (!ft_strchr(temp, '\n'))
	{
		n_read = read(fd, temp, BUFFER_SIZE);
		if (!n_read || n_read == - 1)
			return (NULL);
		line = ft_strjoin(the_string, temp);
		if (!line || !(*temp))
			return (NULL);
		the_string = line;
	}
	the_string = ft_strchr(temp, '\n');
	return (line);
}