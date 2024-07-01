/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:37:51 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/01 18:12:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	player_move_up(t_game *game);
static void	player_move_down(t_game *game);
static void	player_move_left(t_game *game);
static void	player_move_right(t_game *game);

int	player_move(t_game *game)
{
	if (!game || !game->player)
		return (1);
	if (game->player->velocity.y == -1)
		player_move_up(game);
	else if (game->player->velocity.y == 1)
		player_move_down(game);
	else if (game->player->velocity.x == -1)
		player_move_left(game);
	else if (game->player->velocity.x == 1)
		player_move_right(game);
	return (0);
}

static void	player_move_up(t_game *game)
{
	if (!game || !game->player)
		return ;
	if (check_player_collisions(game, (t_vector2){0, -PLAYER_SPEED}))
	{
		game->player->velocity.y = 0;
		return ;
	}
	game->player->position.y -= PLAYER_SPEED;
	animate_player(game->player, game->player->sprites->player_up);
	game->player->move_count++;
	ft_printf("Number of Moves: %d\n", game->player->move_count);
}

static void	player_move_down(t_game *game)
{
	if (!game || !game->player)
		return ;
	if (check_player_collisions(game, (t_vector2){0, PLAYER_SPEED}))
	{
		game->player->velocity = (t_vector2){0, 0};
		return ;
	}
	game->player->position.y += PLAYER_SPEED;
	animate_player(game->player, game->player->sprites->player_down);
	game->player->move_count++;
	ft_printf("Number of Moves: %d\n", game->player->move_count);
}

static void	player_move_left(t_game *game)
{
	if (!game || !game->player)
		return ;
	if (check_player_collisions(game, (t_vector2){-PLAYER_SPEED, 0}))
	{
		game->player->velocity = (t_vector2){0, 0};
		return ;
	}
	game->player->position.x -= PLAYER_SPEED;
	animate_player(game->player, game->player->sprites->player_left);
	game->player->move_count++;
	ft_printf("Number of Moves: %d\n", game->player->move_count);
}

static void	player_move_right(t_game *game)
{
	if (!game || !game->player)
		return ;
	if (check_player_collisions(game, (t_vector2){PLAYER_SPEED, 0}))
	{
		game->player->velocity = (t_vector2){0, 0};
		return ;
	}
	game->player->position.x += PLAYER_SPEED;
	animate_player(game->player, game->player->sprites->player_right);
	game->player->move_count++;
	ft_printf("Number of Moves: %d\n", game->player->move_count);
}
