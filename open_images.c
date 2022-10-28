/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:35 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:41:07 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_wallimgs_up(t_game *game);
void	open_wallimgs_down(t_game *game);

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/Sam_01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/Sam_02.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/puller.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_01.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_wallimgs_up (game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
	open_door_imgs(game);
}
