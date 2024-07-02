/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:24:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/02 15:37:49 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/assets.h"

t_game	*initalize_game(char *file_name)
{
	t_game	*game;
	t_map	*map;

	map = create_map_grid(file_name);
	game = malloc(sizeof(t_game));
	if (!game)
		handle_error(game, "Memory Allocation Failure");
	game->map = map;
	game->data = open_window(game->map->columns * TILE_SIZE,
			game->map->rows * TILE_SIZE, "so_long", handle_error);
	if (!game->data->mlx_ptr || !game->data->win_ptr)
		handle_error(game, "Memory Allocation Failure");
	game->collectable_tex = load_texture(game->data, DOT);
	game->background_tex = create_image(game->data, TILE_SIZE, TILE_SIZE);
	game->exit_tex = load_texture(game->data, BIG_DOT);
	game->wall_tex = load_texture(game->data, MAP_WALL);
	game->player = create_player(game, map->spawn_pos);
	game->stop_render = false;
	return (game);
}
