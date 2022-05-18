/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:42:59 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/05/17 23:40:41 by lbiasuz          ###   ########.fr       */
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
	char	*temp;
	char	*to_read;
	int		n_read;

	if (!*str_hold)
	{
		str_hold[0] = malloc((sizeof(char) * BUFFER_SIZE + 1));
		n_read = read(fd, str_hold[0], BUFFER_SIZE);
		str_hold[n_read] = 0;
	}
	else
	{
		to_read = malloc((sizeof(char) * BUFFER_SIZE + 1));
		n_read = read(fd, to_read, BUFFER_SIZE);
		temp = ft_strjoin(str_hold, &to_read);
		free(to_read);
		free(str_hold[0]);
		str_hold[0] = temp;
		str_hold[n_read] = 0;
	}
	return (!ft_strchr(str_hold[0], '\n')
		&& !(n_read < BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	static char	*str_hold;

	if (!BUFFER_SIZE || fd < 0 || read(fd, str_hold, 0) < 0)
		return (NULL);
	if (!str_hold)
		str_hold = NULL;
	while (read_file(fd, &str_hold))
		;
	return ("alguma coisa");
}
