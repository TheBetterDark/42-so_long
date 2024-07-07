/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:47 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/07 18:39:46 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/assets.h"

t_player	*create_player(t_game *game, t_vector2 spawn_pos)
{
	t_player	*player;
	t_data		*data;

	data = game->data;
	player = malloc(sizeof(t_player));
	if (!player)
		handle_error(game, "Unable to allocate memory for 'player' struct");
	player->current_image = load_texture(game->data, PLAYER_RIGHT_1);
	player->events[0] = connect_event(KEY_W, move_player_event);
	player->events[1] = connect_event(KEY_S, move_player_event);
	player->events[2] = connect_event(KEY_A, move_player_event);
	player->events[3] = connect_event(KEY_D, move_player_event);
	player->position = (t_vector2){spawn_pos.x * TILE_SIZE, spawn_pos.y
		* TILE_SIZE};
	player->velocity = (t_vector2){0, 0};
	player->move_count = 0;
	game->player = player;
	return (player);
}

void	handle_player_event(int key_code, t_game *game)
{
	t_player	*player;
	int			i;

	player = game->player;
	if (!player)
		return ;
	i = 0;
	while (i <= 3)
	{
		if (player->events[i]->key_code == key_code)
		{
			player->events[i]->event_handler(key_code, game);
			break ;
		}
		i++;
	}
}

void	move_player_event(int key_code, t_game *game)
{
	if (!game->player)
		return ;
	if (key_code == KEY_W)
		game->player->velocity = (t_vector2){0, -1};
	else if (key_code == KEY_S)
		game->player->velocity = (t_vector2){0, 1};
	else if (key_code == KEY_A)
		game->player->velocity = (t_vector2){-1, 0};
	else if (key_code == KEY_D)
		game->player->velocity = (t_vector2){1, 0};
}
