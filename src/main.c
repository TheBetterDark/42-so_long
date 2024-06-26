/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/06 22:41:10 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	on_key_event(int key_code, t_game *game);
static int	cleanup_game(t_game *game);

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->data = open_window(300, 300, "so_long", cleanup_game);
	game->background = NULL;
	if (!game->data->mlx_ptr || !game->data->win_ptr)
		return (EXIT_FAILURE);
	create_player(game, (t_vector2){150, 150});
	mlx_hook(game->data->win_ptr, KeyPress, KeyPressMask, on_key_event, game);
	mlx_hook(game->data->win_ptr, DestroyNotify, NoEventMask, cleanup_game,
		game);
	mlx_loop_hook(game->data->mlx_ptr, render_loop, game);
	mlx_loop(game->data->mlx_ptr);
	return (cleanup_game(game), EXIT_FAILURE);
}

static int	on_key_event(int key_code, t_game *game)
{
	if (game || !game->data)
		return (-1);
	handle_player_event(key_code, game);
	return (0);
}

static int	cleanup_game(t_game *game)
{
	t_data	*data;

	data = game->data;
	cleanup_player(game->player);
	if (game)
		free(game);
	return (close_window(data));
}
