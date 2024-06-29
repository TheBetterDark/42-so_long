/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:24:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/28 20:38:49 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/assets.h"

t_game	*initalize_game(void)
{
	t_game	*game;
	t_map	*map;

	map = create_map_grid("./assets/maps/test.ber");
	game = malloc(sizeof(t_game));
	if (!game)
		handle_error(game, "Memory Allocation Failure");
	game->map = map;
	game->data = open_window(game->map->columns * TILE_SIZE,
			game->map->rows * TILE_SIZE, "so_long", handle_error);
	if (!game->data->mlx_ptr || !game->data->win_ptr)
		handle_error(game, "Memory Allocation Failure");
	game->player = create_player(game, (t_vector2){0, 0});
	game->test_tex = load_texture(game->data, MAP_WALL);
	game->stop_render = false;
	return (game);
}
