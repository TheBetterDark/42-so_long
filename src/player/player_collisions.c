/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:25:10 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/07 18:39:16 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	check_collectable_collision(t_bounding_box plr_bounds,
				t_game *game);
static bool	check_wall_collisions(t_bounding_box plr_bounds, t_game *game);
static void	check_exit_collision(t_bounding_box plr_bounds, t_game *game);

bool	check_player_collisions(t_game *game, t_vector2 direction)
{
	const t_bounding_box	player_collision_box = {
		game->player->position.x + direction.x,
		game->player->position.y + direction.y,
		game->player->current_image->height, game->player->current_image->width
	};

	if (check_wall_collisions(player_collision_box, game))
		return (true);
	check_collectable_collision(player_collision_box, game);
	check_exit_collision(player_collision_box, game);
	return (false);
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
					return (true);
			}
			current_pos.x++;
		}
		current_pos.y++;
	}
	return (false);
}

static void	check_collectable_collision(t_bounding_box plr_bounds, t_game *game)
{
	t_bounding_box	collectable_collision_box;
	t_vector2		current_pos;

	current_pos.y = 0;
	while (current_pos.y < game->map->rows)
	{
		current_pos.x = 0;
		while (current_pos.x < game->map->columns)
		{
			if (game->map->grid[current_pos.y][current_pos.x] == COLLECTABLE)
			{
				collectable_collision_box = (t_bounding_box){
					current_pos.x * TILE_SIZE, current_pos.y * TILE_SIZE,
					game->collectable_tex->height, game->collectable_tex->width
				};
				if (check_bounding_box(plr_bounds, collectable_collision_box))
				{
					game->map->grid[current_pos.y][current_pos.x] = EMPTY;
					game->map->collectable_count--;
				}
			}
			current_pos.x++;
		}
		current_pos.y++;
	}
}

static void	check_exit_collision(t_bounding_box plr_bounds, t_game *game)
{
	t_bounding_box	exit_collision_box;
	t_vector2		exit_pos;

	if (game->map->collectable_count > 0)
		return ;
	exit_pos = game->map->exit_pos;
	if (game->map->grid[exit_pos.y][exit_pos.x] == EXIT)
	{
		exit_collision_box = (t_bounding_box){
			exit_pos.x * TILE_SIZE, exit_pos.y * TILE_SIZE,
			game->exit_tex->height, game->exit_tex->width
		};
		if (check_bounding_box(plr_bounds, exit_collision_box))
			cleanup_game(game);
	}
}
