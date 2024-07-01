/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/01 18:00:00 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	render_sprites(t_game *game);
static void	render_static(t_game *game);

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
		mlx_clear_window(game->data->mlx_ptr, game->data->win_ptr);
		player_move(game);
		render_static(game);
		render_sprites(game);
	}
	return (0);
}

static void	render_static(t_game *game)
{
	t_vector2	curr_pos;

	curr_pos.y = 0;
	while (curr_pos.y < game->map->rows)
	{
		curr_pos.x = 0;
		while (curr_pos.x < game->map->columns)
		{
			if (game->map->grid[curr_pos.y][curr_pos.x] == WALL)
				mlx_put_image_to_window(game->data->mlx_ptr,
					game->data->win_ptr, game->wall_tex->img_ptr,
					curr_pos.x * TILE_SIZE, curr_pos.y * TILE_SIZE);
			else if (game->map->grid[curr_pos.y][curr_pos.x] == COLLECTABLE)
				mlx_put_image_to_window(game->data->mlx_ptr,
					game->data->win_ptr, game->collectable_tex->img_ptr,
					curr_pos.x * TILE_SIZE, curr_pos.y * TILE_SIZE);
			else if (game->map->grid[curr_pos.y][curr_pos.x] == EXIT)
				mlx_put_image_to_window(game->data->mlx_ptr,
					game->data->win_ptr, game->exit_tex->img_ptr,
					curr_pos.x * TILE_SIZE, curr_pos.y * TILE_SIZE);
			curr_pos.x++;
		}
		curr_pos.y++;
	}
}

static void	render_sprites(t_game *game)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		game->player->current_image->img_ptr, game->player->position.x,
		game->player->position.y);
}
