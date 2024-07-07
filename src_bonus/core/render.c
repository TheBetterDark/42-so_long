/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/07 18:25:43 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	render_sprites(t_game *game);
static void	render_static(t_game *game);
static void	render_ui(t_game *game);

int	render_loop(t_game *game)
{
	static int	frame_count = 0;

	if (game->stop_render)
		return (1);
	frame_count++;
	if (frame_count < 5000)
		return (1);
	mlx_clear_window(game->data->mlx_ptr, game->data->win_ptr);
	player_move(game);
	render_static(game);
	render_sprites(game);
	render_ui(game);
	frame_count = 0;
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
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		game->player->current_image->img_ptr, game->player->position.x,
		game->player->position.y);
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		game->blinky->current_image->img_ptr, game->blinky->position.x,
		game->blinky->position.y);
	//mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
	//	game->clyde->current_image->img_ptr, game->clyde->position.x,
	//	game->clyde->position.y);
	//mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
	//	game->inky->current_image->img_ptr, game->inky->position.x,
	//	game->blinky->position.y);
	//mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
	//	game->pinky->current_image->img_ptr, game->pinky->position.x,
	//	game->pinky->position.y);
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
