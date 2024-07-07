/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:39:01 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/07 22:56:06 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static double		distance(int x1, int y1, int x2, int y2);
static void			follow_player(t_enemy *enemy, t_game *game);
static t_vector2	find_new_position(t_enemy *enemy, t_game *game,
						double smallest_distance, double dist);

void	enemy_move(t_game *game)
{
	if (!game)
		return ;
	if (game->blinky)
		follow_player(game->blinky, game);
	if (game->clyde)
		follow_player(game->clyde, game);
	if (game->inky)
		follow_player(game->inky, game);
	if (game->pinky)
		follow_player(game->pinky, game);
}

static double	distance(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static t_vector2	find_new_position(t_enemy *enemy, t_game *game,
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
				dist = distance(current_position.x, current_position.y,
						game->player->position.x, game->player->position.y);
				if (dist < smallest_distance)
				{
					smallest_distance = dist;
					new_position = current_position;
				}
			}
			current_position.y ++;
		}
		current_position.x ++;
	}
	return (new_position);
}

static void	follow_player(t_enemy *enemy, t_game *game)
{
	enemy->position = find_new_position(enemy, game, DBL_MAX, 0.0);
}
