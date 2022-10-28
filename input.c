/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:24 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:40:03 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemies(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	pick_collect(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

t_bool	player_movements(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		end_program(game);
	else if (tile->type == ENEMY)
		end_program(game);
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = player_movements(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = player_movements(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = player_movements(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = player_movements(game, game->player.tile->right);
	else
		return (0);
	if (moved)
	{
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		write(1, "\n", 1);
	}
	return (1);
}
