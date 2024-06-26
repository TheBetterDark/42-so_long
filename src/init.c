/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:24:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/07 20:27:17 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// TODO: Add argument for the grid (for storing in struct & positioning stuff)
// TODO: The argument should be a struct containing grid, x & y len & positions
t_game	*initalize_game(void *error_handler)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		handle_error(game);
	game->data = open_window(300, 300, "so_long", cleanup_game);
	if (!game->data->mlx_ptr || !game->data->win_ptr)
		handle_error(game);
	game->player = create_player(game, (t_vector2){150, 150});
	game->background = NULL;
	game->map = NULL;
	game->stop_render = NULL;
	return (game);
}
