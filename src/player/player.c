/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:47 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/29 14:56:45 by muabdi           ###   ########.fr       */
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
	player->sprites = load_player_sprites(game->data);
	player->events[0] = connect_event(KEY_W, player_move_up, data);
	player->events[1] = connect_event(KEY_S, player_move_down, data);
	player->events[2] = connect_event(KEY_A, player_move_left, data);
	player->events[3] = connect_event(KEY_D, player_move_right, data);
	player->position = spawn_pos;
	player->animation_step = 1;
	game->player = player;
	return (player);
}

t_player_sprites	*load_player_sprites(t_data *data)
{
	t_player_sprites	*sprites;
	t_vector2			pos;

	sprites = malloc(sizeof(t_player_sprites));
	if (!sprites)
		return (NULL);
	pos = (t_vector2){0, 0};
	sprites->player_up->step_1 = create_texture(data, PLAYER_UP_1, pos);
	sprites->player_up->step_2 = create_texture(data, PLAYER_UP_2, pos);
	sprites->player_up->step_3 = create_texture(data, PLAYER_UP_3, pos);
	sprites->player_down->step_1 = create_texture(data, PLAYER_DOWN_1, pos);
	sprites->player_down->step_2 = create_texture(data, PLAYER_DOWN_2, pos);
	sprites->player_down->step_3 = create_texture(data, PLAYER_DOWN_3, pos);
	sprites->player_left->step_1 = create_texture(data, PLAYER_LEFT_1, pos);
	sprites->player_left->step_2 = create_texture(data, PLAYER_LEFT_2, pos);
	sprites->player_left->step_3 = create_texture(data, PLAYER_LEFT_3, pos);
	sprites->player_right->step_1 = create_texture(data, PLAYER_RIGHT_1, pos);
	sprites->player_right->step_2 = create_texture(data, PLAYER_RIGHT_2, pos);
	sprites->player_right->step_3 = create_texture(data, PLAYER_RIGHT_3, pos);
	return (sprites);
}

void	animate_player(t_player *player, t_direction direction)
{
}

void	render_player(t_game *game)
{
}

//TODO: Cleanup