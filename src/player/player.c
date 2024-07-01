/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:47 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/01 12:59:49 by muabdi           ###   ########.fr       */
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
	player->sprites = load_player_sprites(game->data);
	player->current_image = player->sprites->player_left->step_1;
	player->events[0] = connect_event(KEY_W, player_move_up);
	player->events[1] = connect_event(KEY_S, player_move_down);
	player->events[2] = connect_event(KEY_A, player_move_left);
	player->events[3] = connect_event(KEY_D, player_move_right);
	player->position = (t_vector2){spawn_pos.x * TILE_SIZE, spawn_pos.y
		* TILE_SIZE};
	player->animation_step = 1;
	player->move_count = 0;
	player->has_changed = true;
	game->player = player;
	return (player);
}

// TODO: Make this into a util (loading animations into the struct)
t_player_sprites	*load_player_sprites(t_data *data)
{
	t_player_sprites	*sprites;
	t_vector2			pos;

	sprites = malloc(sizeof(t_player_sprites));
	if (!sprites)
		return (NULL);
	pos = (t_vector2){0, 0};
	sprites->player_up = malloc(sizeof(t_animation));
	sprites->player_down = malloc(sizeof(t_animation));
	sprites->player_left = malloc(sizeof(t_animation));
	sprites->player_right = malloc(sizeof(t_animation));
	sprites->player_up->step_1 = load_texture(data, PLAYER_UP_1);
	sprites->player_up->step_2 = load_texture(data, PLAYER_UP_2);
	sprites->player_up->step_3 = load_texture(data, PLAYER_UP_3);
	sprites->player_down->step_1 = load_texture(data, PLAYER_DOWN_1);
	sprites->player_down->step_2 = load_texture(data, PLAYER_DOWN_2);
	sprites->player_down->step_3 = load_texture(data, PLAYER_DOWN_3);
	sprites->player_left->step_1 = load_texture(data, PLAYER_LEFT_1);
	sprites->player_left->step_2 = load_texture(data, PLAYER_LEFT_2);
	sprites->player_left->step_3 = load_texture(data, PLAYER_LEFT_3);
	sprites->player_right->step_1 = load_texture(data, PLAYER_RIGHT_1);
	sprites->player_right->step_2 = load_texture(data, PLAYER_RIGHT_2);
	sprites->player_right->step_3 = load_texture(data, PLAYER_RIGHT_3);
	return (sprites);
}

void	animate_player(t_player *player, t_animation *animation)
{
	if (!player || !animation)
		return ;
	player->animation_step++;
	if (player->animation_step >= 3)
		player->animation_step = 1;
	if (player->animation_step == 1)
		player->current_image = animation->step_1;
	else if (player->animation_step == 2)
		player->current_image = animation->step_2;
	else if (player->animation_step == 3)
		player->current_image = animation->step_3;
	player->has_changed = true;
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
