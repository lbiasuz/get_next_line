/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:42:59 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/18 23:44:49 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_if_content(char **mall)
{
	if (mall && mall[0])
	{
		free(mall[0]);
		mall[0] = NULL;
	}
}

int	read_file(int fd, char **str_hold)
{
	char	*to_read;
	int		n_read;
	char	*temp;

	to_read = malloc((sizeof(char) * BUFFER_SIZE + 1));
	n_read = read(fd, to_read, BUFFER_SIZE);
	if (n_read < 0)
		return (n_read);
	to_read[n_read] = 0;
	if (!str_hold[0])
		str_hold[0] = to_read;
	else
	{
		temp = ft_strjoin(str_hold, &to_read);
		free(str_hold[0]);
		free(to_read);
		str_hold[0] = temp;
	}
	return (*ft_strchr(str_hold[0], '\n') == 0 && n_read == BUFFER_SIZE);
}

char	*gen_line(char **s_src)
{
	char	*nlp;
	char	*temp;
	char	*post;

	nlp = ft_strchr(*s_src, '\n');
	if (nlp)
	{
		post = ft_substr(s_src[0], nlp - s_src[0] + 1, ft_strchr(nlp, 0) - nlp);
		temp = ft_substr(s_src[0], 0, nlp - s_src[0] + 1);
		free_if_content(s_src);
		s_src[0] = post;
		return (temp);
	}
	return (*s_src);
}

char	*get_next_line(int fd)
{
	int			keep_reading;
	static char	*str_hold;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, str_hold, 0) < 0)
		return (NULL);
	if (!str_hold)
		str_hold = NULL;
	keep_reading = 1;
	while (keep_reading > 0)
		keep_reading = read_file(fd, &str_hold);
	line = gen_line(&str_hold);
	// if (keep_reading == -1)
	// 	free(str_hold);
	return (line);
}
