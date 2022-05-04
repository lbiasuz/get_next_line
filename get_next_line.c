/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:05 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/04 00:41:28 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	const char	*the_string;
	char		*line;
	char		*temp;
	int			n_read;

	temp = "";
	while (!ft_strchr(temp, '\n'))
	{
		read(fd, temp, BUFFER_SIZE);
		line = ft_strjoin(the_string, temp);
		if (!line || !(*temp))
			return (NULL);
		the_string = line;
	}
	the_string = ft_strchr(temp, '\n');
	return (line);
}