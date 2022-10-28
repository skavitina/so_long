/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:39:13 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:21:42 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animation(t_player *player)
{
	static int	a;

	if (a < 20)
		player->current_img = player->idle_img_1;
	else if (a > 20)
		player->current_img = player->idle_img_0;
	a++;
	if (a > 40)
		a = 0;
}

int	update(t_game *game)
{
	animation(&game->player);
	render(*game);
	return (1);
}
