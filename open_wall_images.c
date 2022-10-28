/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wall_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:38:44 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:41:14 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_wallimgs_up(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->empty = mlx_xpm_file_to_image(game->mlx,
			"sprites/empty.xpm", &game->img_size.x, &game->img_size.y);
}

void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	(void)tile;
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}
