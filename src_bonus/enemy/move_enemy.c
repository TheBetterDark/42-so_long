/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:39:01 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/23 16:41:29 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static t_vector2	find_new_position(t_game *game, t_enemy *enemy,
						double smallest_distance, double dist);
static void			follow_player(t_game *game, t_enemy *enemy);

void	enemy_move(t_game *game)
{
	if (!game)
		return ;
	if (game->blinky)
		follow_player(game, game->blinky);
}

// TODO: Stop enemy from moving diagonally
// TODO: Improve path finding so it doesnt get stuck

static t_vector2	find_new_position(t_game *game, t_enemy *enemy,
				double smallest_distance, double dist)
{
	t_vector2	new_position;
	t_vector2	current_position;

	current_position.x = (enemy->position.x - 1);
	while (current_position.x <= (enemy->position.x + 1))
	{
		current_position.y = enemy->position.y - 1;
		while (current_position.y <= (enemy->position.y + 1))
		{
			if (!check_enemy_collisions(game, enemy, current_position))
			{
				dist = sqrt(pow(game->player->position.x - current_position.x,
							2) + pow(game->player->position.y
							- current_position.y, 2));
				if (dist < smallest_distance)
				{
					smallest_distance = dist;
					new_position = current_position;
				}
			}
			current_position.y++;
		}
		current_position.x++;
	}
	return (new_position);
}

static void	follow_player(t_game *game, t_enemy *enemy)
{
	enemy->position = find_new_position(game, enemy, DBL_MAX, 0.0);
}
