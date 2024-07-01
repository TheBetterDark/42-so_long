/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:25:10 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/30 23:11:06 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

bool	check_player_collisions(t_game *game, t_vector2 direction)
{
	t_player	*player;
	//t_image		*wall;

	player = game->player;
	return (check_bounding_box(
			(t_bounding_box){player->position.x + direction.x,
			player->position.y + direction.y,
			player->current_image->height, player->current_image->width},
		(t_bounding_box){-1, -1, -1, -1}
	));
}
