/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:25:10 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/01 14:35:11 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include <stdbool.h>

static bool	check_wall_collisions(t_bounding_box plr_bounds, t_game *game);

bool	check_player_collisions(t_game *game, t_vector2 direction)
{
	const t_bounding_box	player_collision_box = {
		game->player->position.x + direction.x,
		game->player->position.y + direction.y,
		game->player->current_image->height, game->player->current_image->width
	};

	if (check_wall_collisions(player_collision_box, game))
		return (false);
	return (true);
}

static bool	check_wall_collisions(t_bounding_box plr_bounds, t_game *game)
{
	t_bounding_box	wall_collision_box;		
	t_vector2		current_pos;

	current_pos.y = 0;
	while (current_pos.y < game->map->rows)
	{
		current_pos.x = 0;
		while (current_pos.x < game->map->columns)
		{
			if (game->map->grid[current_pos.y][current_pos.x] == WALL)
			{
				wall_collision_box = (t_bounding_box){
					current_pos.x * TILE_SIZE, current_pos.y * TILE_SIZE,
					game->wall_tex->height, game->wall_tex->width
				};
				if (check_bounding_box(plr_bounds, wall_collision_box))
					return (false);
			}
			current_pos.x++;
		}
		current_pos.y++;
	}
	return (true);
}
