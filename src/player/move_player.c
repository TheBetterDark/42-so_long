/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:37:51 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/30 21:42:01 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	print_moves(t_player *player);

void	*player_move_up(int key_code, t_game *game)
{
	t_vector2	previous_position;
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_W)
		return (NULL);
	previous_position = player->position;
	player->position.y -= PLAYER_SPEED;
	if (check_player_collisions(game, (t_vector2){0, -PLAYER_SPEED}))
	{
		player->position.y = TILE_SIZE
			* (int)(round((double)player->position.y / (double)TILE_SIZE));
		if (check_player_collisions(game, (t_vector2){0, 0}))
		{
			player->position = previous_position;
			return (NULL);
		}
	}
	animate_player(player, player->sprites->player_up);
	print_moves(player);
	return (NULL);
}

void	*player_move_down(int key_code, t_game *game)
{
	t_vector2	previous_position;
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_S)
		return (NULL);
	previous_position = player->position;
	player->position.y += PLAYER_SPEED;
	if (check_player_collisions(game, (t_vector2){0, PLAYER_SPEED}))
	{
		player->position.y = TILE_SIZE
			* (int)(round((double)player->position.y / (double)TILE_SIZE));
		if (check_player_collisions(game, (t_vector2){0, 0}))
		{
			player->position = previous_position;
			return (NULL);
		}
	}
	animate_player(player, player->sprites->player_down);
	print_moves(player);
	return (NULL);
}

void	*player_move_left(int key_code, t_game *game)
{
	t_vector2	previous_position;
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_A)
		return (NULL);
	previous_position = player->position;
	player->position.x -= PLAYER_SPEED;
	if (check_player_collisions(game, (t_vector2){-PLAYER_SPEED, 0}))
	{
		player->position.x = TILE_SIZE
			* (int)(round((double)player->position.x / (double)TILE_SIZE));
		if (check_player_collisions(game, (t_vector2){0, 0}))
		{
			player->position = previous_position;
			return (NULL);
		}
	}
	animate_player(player, player->sprites->player_left);
	print_moves(player);
	return (NULL);
}

void	*player_move_right(int key_code, t_game *game)
{
	t_vector2	previous_position;
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_D)
		return (NULL);
	previous_position = player->position;
	player->position.x += PLAYER_SPEED;
	if (check_player_collisions(game, (t_vector2){PLAYER_SPEED, 0}))
	{
		player->position.x = TILE_SIZE
			* (int)(round((double)player->position.x / (double)TILE_SIZE));
		if (check_player_collisions(game, (t_vector2){0, 0}))
		{
			player->position = previous_position;
			return (NULL);
		}
	}
	animate_player(player, player->sprites->player_right);
	print_moves(player);
	return (NULL);
}

static void	print_moves(t_player *player)
{
	player->move_count++;
	ft_printf("Number of Moves: %d\n", player->move_count);
}
