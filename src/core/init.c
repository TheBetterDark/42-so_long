/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:24:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/03 15:41:09 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/assets.h"

static bool	validate_file_type(char *file_name);

t_game	*initalize_game(char *file_name)
{
	t_game	*game;
	t_map	*map;

	if (!validate_file_type(file_name))
		handle_error(NULL, "Invalid File Type");
	map = create_map_grid(file_name);
	game = malloc(sizeof(t_game));
	if (!game)
		handle_error(game, "Memory Allocation Failure");
	game->map = map;
	game->data = open_window(game->map->columns * TILE_SIZE,
			(game->map->rows * TILE_SIZE) + TILE_SIZE, "so_long", handle_error);
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

int	cleanup_game(t_game *game)
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

static bool	validate_file_type(char *file_name)
{
	const int	size = ft_strlen(file_name);

	if (ft_strnstr(&file_name[size - 4], ".ber", size))
		return (true);
	return (false);
}
