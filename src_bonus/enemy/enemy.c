/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:55:27 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/04 17:17:34 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

t_enemy	*create_enemy(t_game *game, t_vector2 spawn_pos, char *tex_path)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		handle_error(game, "Unable to allocate memory for 'enemy' struct");
	enemy->current_image = load_texture(game->data, tex_path);
	enemy->position = (t_vector2){spawn_pos.x * TILE_SIZE, spawn_pos.y
		* TILE_SIZE};
	enemy->velocity = (t_vector2){0, 0};
	return (enemy);
}
