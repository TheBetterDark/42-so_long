/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:24:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/26 21:00:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/assets.h"

// TODO: Add argument for the grid (for storing in struct & positioning stuff)
// TODO: The argument should be a struct containing grid, x & y len & positions
t_game	*initalize_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		handle_error(game, "");
	game->map = create_map_grid("./assets/maps/test.ber");
	game->data = open_window(300, 300, "so_long", handle_error);
	if (!game->data->mlx_ptr || !game->data->win_ptr)
		handle_error(game, "");
	game->background = create_image(game->data, game->data->width,
			game->data->height);
	game->map = NULL;
	game->player = create_player(game, (t_vector2){150, 150});
	game->test_tex = load_texture(game->data, MAP_WALL);
	game->stop_render = false;
	return (game);
}
