/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:09:06 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/11 22:20:33 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_moves(t_player *player);

void	*player_move_up(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_W)
		return (NULL);
	if (check_player_collisions(game, (t_vector2){0, -5}))
		return (NULL);
	player->position.y -= 5;
	animate_player(player, player->sprites->player_up);
	print_moves(player);
	return (NULL);
}

void	*player_move_down(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_S)
		return (NULL);
	if (check_player_collisions(game, (t_vector2){0, 5}))
		return (NULL);
	player->position.y += 5;
	animate_player(player, player->sprites->player_down);
	print_moves(player);
	return (NULL);
}

void	*player_move_left(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_A)
		return (NULL);
	if (check_player_collisions(game, (t_vector2){-5, 0}))
		return (NULL);
	player->position.x -= 5;
	animate_player(player, player->sprites->player_left);
	print_moves(player);
	return (NULL);
}

void	*player_move_right(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_D)
		return (NULL);
	if (check_player_collisions(game, (t_vector2){5, 0}))
		return (NULL);
	player->position.x += 5;
	animate_player(player, player->sprites->player_right);
	print_moves(player);
	return (NULL);
}

static void	print_moves(t_player *player)
{
	player->move_count++;
	ft_printf("Number of Moves: %d\n", player->move_count);
}
