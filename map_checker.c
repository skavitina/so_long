/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:39:49 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:38:35 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c);
int	valid_uniquechar(char c, char checker, t_bool *bool);
int	valid_border(char c, t_vector point, t_vector size);

int	valid_file(int argc, char *file)
{
	if (argc == 1)
	{
		write(1, "no arguments\n", 13);
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		write(1, "too many arguments\n", 19);
		exit(EXIT_FAILURE);
	}
	if (!ft_strend_cmp(file, ".ber"))
	{
		write(1, "map should be a .ber file\n", 26);
		exit(EXIT_FAILURE);
	}
	return (1);
}

static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = line_counts(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

static int	checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
	{
		write(1, "invalid map character\n", 22);
		exit(EXIT_FAILURE);
	}
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
	{
		write(1, "must be only one player 'P'\n", 28);
		exit(EXIT_FAILURE);
	}
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
	{
		write(1, "map must be surrounded by walls\n", 32);
		exit(EXIT_FAILURE);
	}
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

static void	errors(int n)
{
	if (n == 1)
		write (1, "map must be rectangular\n", 24);
	else
		write (1, "there must be one 'P' and 'E', and at least one 'C'\n", 52);
	exit(EXIT_FAILURE);
}

int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	t_bool				valid;

	data = init_checkerdata(map);
	valid = TRUE;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != (size_t)data.size.x)
			errors(1);
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		errors(2);
	return (valid);
}
