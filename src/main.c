/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/11 22:13:17 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	on_key_event(int key_code, t_game *game);
static int	cleanup_game(t_game *game);

int	main(void)
{
	t_game	*game;

	game = initalize_game();
	if (!game)
		cleanup_game(game);
	mlx_hook(game->data->win_ptr, KeyPress, KeyPressMask, on_key_event, game);
	mlx_hook(game->data->win_ptr, DestroyNotify, NoEventMask, cleanup_game,
		game);
	mlx_loop_hook(game->data->mlx_ptr, render_loop, game);
	mlx_loop(game->data->mlx_ptr);
	return (cleanup_game(game));
}

static int	on_key_event(int key_code, t_game *game)
{
	if (!game || !game->data)
		return (cleanup_game(game), 1);
	if (key_code == KEY_ESC)
		return (cleanup_game(game), 1);
	handle_player_event(key_code, game);
	return (0);
}

static int	cleanup_game(t_game *game)
{
	if (!game)
		return (handle_error(game, "Unable to free game"), EXIT_FAILURE);
	cleanup_player(game->player);
	clear_image(game->background);
	clear_image(game->test_tex);
	close_window(game->data);
	free(game);
	return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
