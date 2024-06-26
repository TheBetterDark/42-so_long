/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/06 22:43:11 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_loop(t_game *game)
{
	t_player	*player;

	if (game->stop_render)
		return (0);
	player = game->player;
	if (player->has_changed)
	{
		render_background(game, create_rgb(0, 0, 0));
		render_player(game);
	}
	return (0);
}
