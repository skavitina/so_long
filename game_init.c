/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:11 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:39:31 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_tables(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_tables(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	game_initialization(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"Samy boy");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	game_initialization(game);
	return (TRUE);
}
