/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:40:06 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:40:59 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	filecount_strings(char *file)
{
	int		count_strings;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	count_strings = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
		count_strings++;
	}
	close(fd);
	return (count_strings);
}

static char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = filecount_strings(file);
	if (line_count <= 0)
	{
		write(1, "open or reading error, the file may not exist\n", 46);
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		exit(EXIT_FAILURE);
	return (map);
}

char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}
