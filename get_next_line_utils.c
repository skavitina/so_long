/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:35:42 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:39:47 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linelen(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_getline(int len, char *read)
{
	char	*line;
	int		i;

	line = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clearline(int len, char *read)
{
	char	*output;
	int		i;

	if (read == NULL || (ft_strlen(read) - len + 1) == 0)
		return (NULL);
	output = malloc(ft_strlen(read) - len + 1);
	i = 0;
	while (read[len + i])
	{
		output[i] = read[len + i];
		i++;
	}
	output[i] = '\0';
	free (read);
	return (output);
}

int	ft_newread(int fd, char **oldread)
{
	int		count;
	char	newread[BUFFER_SIZE + 1];
	char	*output;
	int		i;
	int		new_i;

	count = read(fd, newread, BUFFER_SIZE);
	newread[count] = '\0';
	output = malloc(ft_strlen(*oldread) + count + 1);
	if (!output)
		return (-1);
	i = 0;
	while (oldread[0][i])
	{	
		output[i] = oldread[0][i];
		i++;
	}
	new_i = 0;
	while (newread[new_i])
		output[i++] = newread[new_i++];
	output[i] = '\0';
	free(*oldread);
	*oldread = output;
	return (count);
}
