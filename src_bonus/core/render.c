/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/08 15:03:32 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include <time.h>

static void	render_sprites(t_game *game);
static void	render_static(t_game *game);
static void	render_ui(t_game *game);

int	render_loop(t_game *game)
{
	static clock_t	last_fps_update = 0;
	static double	delta_time;
	clock_t			current_time;

	if (game->stop_render)
		return (1);
	current_time = clock();
	delta_time = (double)(current_time - last_fps_update)
		/ CLOCKS_PER_SEC;
	if (delta_time >= FIXED_DELTA_TIME)
	{
		last_fps_update = current_time;
		mlx_clear_window(game->data->mlx_ptr, game->data->win_ptr);
		player_move(game);
		enemy_move(game);
		render_static(game);
		render_sprites(game);
		render_ui(game);
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
				if (game->map->collectable_count < 1)
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
	if (game->player)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
			game->player->current_image->img_ptr, game->player->position.x,
			game->player->position.y);
	if (game->blinky)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
			game->blinky->current_image->img_ptr, game->blinky->position.x,
			game->blinky->position.y);
}

static void	render_ui(t_game *game)
{
	char	*steps;
	char	*num;

	num = ft_itoa(game->player->move_count);
	if (!num)
		return ;
	steps = ft_strjoin("Steps: ", num);
	if (!steps)
	{
		free(num);
		return ;
	}
	mlx_string_put(game->data->mlx_ptr, game->data->win_ptr,
		((game->map->columns * TILE_SIZE) / 2) - 25,
		(game->map->rows * TILE_SIZE) + 11,
		create_rgb(255, 255, 255), steps);
	free(num);
	free(steps);
}
