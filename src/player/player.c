/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:47 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/28 23:15:56 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*create_player(t_game *game, t_vector2 spawn_pos)
{
	t_player	*player;
	t_data		*data;

	data = game->data;
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->position = spawn_pos;
	player->asset = PLAYER_LEFT_1;
	player->anim_step = 1;
	player->sprite = create_texture(data, player->asset,
			player->position);
	player->events[0] = connect_event(KEY_W, player_move_up, data);
	player->events[1] = connect_event(KEY_S, player_move_down, data);
	player->events[2] = connect_event(KEY_A, player_move_left, data);
	player->events[3] = connect_event(KEY_D, player_move_right, data);
	player->asset_changed = false;
	player->position_changed = false;
	game->player = player;
	return (player);
}

//TODO: Check if something changed

void	animate_player(t_player *player, t_direction direction)
{
	const char	*assets[4][3] = {
	{PLAYER_UP_1, PLAYER_UP_2, PLAYER_UP_3},
	{PLAYER_DOWN_1, PLAYER_DOWN_2, PLAYER_DOWN_3},
	{PLAYER_LEFT_1, PLAYER_LEFT_2, PLAYER_LEFT_3},
	{PLAYER_RIGHT_1, PLAYER_RIGHT_2, PLAYER_RIGHT_3}
	};

	player->anim_step++;
	if (player->anim_step > 3)
		player->anim_step = 1;
	if (direction >= UP && direction <= RIGHT)
		player->asset = (char *)assets[direction][player->anim_step - 1];
	player->asset_changed = true;
}

void	render_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player)
		return ;
	player->sprite = create_texture(game->data, player->asset,
			player->position);
	player->asset_changed = false;
	player->position_changed = false;
}
