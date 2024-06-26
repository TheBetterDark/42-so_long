/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/28 23:12:52 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	on_key_event(int key_code, t_game *game);
static int	cleanup_game(t_game *game);

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->data = open_window(300, 300, "so_long");
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
	t_event	*current_event;
	t_list	*current_node;
	t_data	*data;

	data = game->data;
	if (data == NULL || data->event_connections == NULL)
		return (-1);
	current_node = data->event_connections;
	while (current_node != NULL)
	{
		current_event = current_node->content;
		if (current_event->key_code == key_code)
			current_event->f(key_code);
		current_node = current_node->next;
	}
	return (0);
}

static int	cleanup_game(t_game *game)
{
	t_data	*data;

	data = game->data;
	if (game->player)
		free(game->player);
	if (game)
		free(game);
	return (close_window(data));
}
