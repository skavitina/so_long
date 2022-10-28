/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:50 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 22:52:41 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->collects--;
	action_anim(&game->player);
}

void	move_to_exit(t_game *game, t_tile *tile)
{
	(void)tile;
	end_program(game);
}

void	move_to_enemy(t_game *game, t_tile *tile)
{
	(void)tile;
	end_program(game);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}
