/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:55:44 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/07 21:33:28 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static bool	check_wall_collisions(t_bounding_box enemy_bounds, t_game *game);
static void	check_player_collision(t_bounding_box enemy_bounds, t_game *game);

bool	check_enemy_collisions(t_game *game, t_enemy *enemy, t_vector2 position)
{
	const t_bounding_box	enemy_collision_box = {
		position.x, position.y,
		enemy->current_image->height, enemy->current_image->width
	};

	if (check_wall_collisions(enemy_collision_box, game))
		return (true);
	check_player_collision(enemy_collision_box, game);
	return (false);
}

static bool	check_wall_collisions(t_bounding_box enemy_bounds, t_game *game)
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
				if (check_bounding_box(enemy_bounds, wall_collision_box))
					return (true);
			}
			current_pos.x++;
		}
		current_pos.y++;
	}
	return (false);
}

static void	check_player_collision(t_bounding_box enemy_bounds, t_game *game)
{
	const t_bounding_box	plr_bounds = {
		game->player->position.x, game->player->position.y,
		game->player->current_image->height, game->player->current_image->width
	};

	if (check_bounding_box(enemy_bounds, plr_bounds))
		cleanup_game(game);
}
