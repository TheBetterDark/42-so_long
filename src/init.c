/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:24:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/01 12:53:03 by muabdi           ###   ########.fr       */
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
	game->collectable_tex = load_texture(game->data, DOT);
	game->background_tex = create_image(game->data, TILE_SIZE, TILE_SIZE);
	game->exit_tex = load_texture(game->data, BIG_DOT);
	game->wall_tex = load_texture(game->data, MAP_WALL);
	game->player = create_player(game, map->spawn_pos);
	ft_printf("Player Spawn: (%d, %d)\n", map->spawn_pos.x, map->spawn_pos.y);
	game->stop_render = false;
	return (game);
}
