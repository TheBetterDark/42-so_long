/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:25:10 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/11 22:16:47 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_player_collisions(t_game *game, t_vector2 direction)
{
	t_player	*player;
	t_image		*wall;

	player = game->player;
	wall = game->test_tex;
	return (check_bounding_box(
			(t_bounding_box){player->position.x + direction.x,
			player->position.y + direction.y,
			player->current_image->height, player->current_image->width},
		(t_bounding_box){100, 100, wall->height, wall->width}
	));
}
