/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:05 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/14 23:31:31 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gen_line(char **s_src)
{
	char	*nlp;
	char	*temp;
	
	nlp = ft_strchr(*s_src, '\n');
	if (nlp)
	{
		temp = ft_substr(*s_src, 0, nlp - *s_src + 1);
		*s_src = nlp + 1;
		return (temp);
	}
	return (*s_src);
}

char	*read_file(int fd)
{
	char	*temp;
	int		n_read;

	temp = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	n_read = read(fd, temp, BUFFER_SIZE);
	if (n_read < 1)
		return ("");
	temp[n_read] = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*the_string;
	char	*temp;

	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	if (!the_string)
		the_string = read_file(fd);
	while (!ft_strchr(&*the_string, '\n'))
	{
		temp = read_file(fd);
		if (ft_strlen(temp) < BUFFER_SIZE)
			return (the_string);
		the_string = ft_strjoin(&*the_string, temp);
	}
	return (gen_line(&the_string));
}
