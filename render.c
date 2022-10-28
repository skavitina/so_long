/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:59 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:41:31 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == EMPTY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.empty, pos.x, pos.y);
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		mlx_put_image_to_window(game.mlx, game.window, \
			game.door_open_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs.img_0, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.current_img, pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.enemy_imgs.basic_01, pos.x, pos.y);
}

static void	draw_effect(t_game game)
{
	if (game.effect.counter < game.effect.frames)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.effect.img, \
			game.effect.pos.x, game.effect.pos.y);
}

static void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.moves);
	mlx_string_put(game.mlx, game.window,
		game.wndw_size.x - IMG_SIZE / 2.3,
		IMG_SIZE - IMG_SIZE / 1.5,
		-1, str);
	free(str);
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			draw_effect(game);
			x++;
		}
		y++;
	}
	draw_text(game);
}
