/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:44:05 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/17 22:51:36 by lbiasuz          ###   ########.fr       */
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

char	*read_file(int fd)
{
	char	*temp;
	int		n_read;

	temp = malloc((sizeof(char) * BUFFER_SIZE + 1) );
	n_read = read(fd, temp, BUFFER_SIZE);
	if (n_read <= 0 || temp == NULL)
		return (NULL);
	temp[n_read] = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*the_string;
	char	*past;
	char	*temp;

	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	if (!the_string)
		the_string = read_file(fd);
	while (!ft_strchr(the_string, '\n'))
	{
		temp = read_file(fd);
		if (!temp && the_string && ft_strlen(the_string))
		{
			temp = the_string;
			the_string += ft_strlen(temp);
			return (temp);
		}
		else if (!temp)
		{
			free_if_content(&the_string);
			return (NULL);
		}
		past = ft_strjoin(&the_string, &temp);
		free(the_string);
		the_string = past;
		free(temp);
	}
	return (gen_line(&the_string));
}
