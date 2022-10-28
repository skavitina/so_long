/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:01 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:39:06 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_to(t_enemy *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	tile->type = ENEMY;
	enemy->tile = tile;
}

t_bool	change_direction(t_enemy *enemy)
{
	if (enemy->dir == 0)
		enemy->dir = 1;
	else
		enemy->dir = 0;
	return (FALSE);
}

t_bool	move_horizontal(t_enemy *enemy, t_game *game)
{
	if (enemy-> dir == 1)
	{
		if (enemy->tile->right->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->right);
			end_program(game);
		}
		else
			return (change_direction(enemy));
	}
	else if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->left);
			end_program(game);
		}
		else
			return (change_direction(enemy));
	}
	return (TRUE);
}

t_bool	move_vertical(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->up);
			end_program(game);
		}
		else
			return (change_direction(enemy));
	}
	else if (enemy-> dir == 1)
	{
		if (enemy->tile->down->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->down);
			end_program(game);
		}
		else
			return (change_direction(enemy));
	}
	return (TRUE);
}

void	move_enemies(t_game *game)
{
	t_enemy	*current;

	if (game->enemy_list == NULL)
		return ;
	current = game->enemy_list;
	while (TRUE)
	{
		if (current->type == HORIZONTAL_ENEM)
			move_horizontal(current, game);
		else if (current->type == VERTICAL_ENEM)
			move_vertical(current, game);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}
