/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/02 15:37:55 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int	on_key_event(int key_code, t_game *game);
static int	cleanup_game(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		handle_error(NULL,
			"Invalid parameter.\nUsage: so_long \"file_name.ber\"\n");
	game = initalize_game(argv[1]);
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
	clear_image(game->collectable_tex);
	clear_image(game->background_tex);
	clear_image(game->exit_tex);
	clear_image(game->wall_tex);
	cleanup_map(game->map);
	close_window(game->data);
	free(game);
	return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
