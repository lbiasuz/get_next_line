/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:42:59 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/20 08:49:22 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_file(int fd, char **str_hold)
{
	char	*to_read;
	int		n_read;
	char	*temp;

	to_read = malloc((sizeof(char) * BUFFER_SIZE + 1));
	n_read = read(fd, to_read, BUFFER_SIZE);
	if (n_read < 0)
		return (n_read);
	to_read[n_read] = 0;
	if (!str_hold || !str_hold[0])
		str_hold[0] = to_read;
	else
	{
		temp = ft_strjoin(str_hold, &to_read);
		free(str_hold[0]);
		free(to_read);
		str_hold[0] = temp;
	}
	return (n_read);
}

char	*gen_line(char **s_src)
{
	int		nlp;
	char	*line;
	char	*post_new_line;

	nlp = ft_strchr(*s_src, '\n');
	if (nlp >= 0)
	{
		post_new_line = ft_substr(
				s_src[0], nlp + 1, ft_strlen(s_src[0] + nlp + 1)
				);
		line = ft_substr(s_src[0], 0, nlp + 1);
		free(*s_src);
		s_src[0] = post_new_line;
		return (line);
	}
	return (ft_substr(s_src[0], 0, ft_strlen(s_src[0])));
}

char	*get_next_line(int fd)
{
	int			keep_reading;
	static char	*str_hold;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, str_hold, 0) < 0)
		return (NULL);
	while (ft_strchr(str_hold, '\n') == -1)
	{
		keep_reading = read_file(fd, &str_hold);
		if (keep_reading < 1)
			return (NULL);
		else if (keep_reading < BUFFER_SIZE)
		{
			line = gen_line(&str_hold);
			free(str_hold);
			return (line);
		}
	}
	return (gen_line(&str_hold));
}
