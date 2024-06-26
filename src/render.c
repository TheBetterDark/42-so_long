/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/26 14:41:45 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	render_game_image(t_game *game);
static void	render_player(t_game *game);

int	render_loop(t_game *game)
{
	static clock_t	last_fps_update = 0;
	static int		frame_count;
	static double	fps;
	clock_t			current_time;

	frame_count = 0;
	fps = 0;
	if (game->stop_render)
		return (0);
	frame_count++;
	current_time = clock();
	game->data->delta_time = (double)(current_time - last_fps_update)
		/ CLOCKS_PER_SEC;
	if (game->data->delta_time >= FIXED_DELTA_TIME)
	{
		fps = frame_count / game->data->delta_time;
		last_fps_update = current_time;
		frame_count = 0;
		render_game_image(game);
	}
	return (0);
}

static void	render_game_image(t_game *game)
{
	if (game->player->has_changed)
	{
		mlx_clear_window(game->data->mlx_ptr, game->data->win_ptr);
		render_player(game);
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
			game->test_tex->img_ptr, 0, 0);
	}
}

static void	render_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player)
		return ;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		player->current_image->img_ptr, player->position.x,
		player->position.y);
	player->has_changed = false;
}
