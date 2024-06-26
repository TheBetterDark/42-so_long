/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:09:06 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/06 23:14:11 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*player_move_up(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_W)
		return (NULL);
	player->position.y -= 5;
	animate_player(player, player->sprites->player_up);
	return (NULL);
}

void	*player_move_down(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_S)
		return (NULL);
	player->position.y += 5;
	animate_player(player, player->sprites->player_down);
	return (NULL);
}

void	*player_move_left(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_A)
		return (NULL);
	player->position.x -= 5;
	animate_player(player, player->sprites->player_left);
	return (NULL);
}

void	*player_move_right(int key_code, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player || key_code != KEY_D)
		return (NULL);
	player->position.x += 5;
	animate_player(player, player->sprites->player_right);
	return (NULL);
}
