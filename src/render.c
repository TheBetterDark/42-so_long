/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/11 21:23:15 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_loop(t_game *game)
{
	t_player	*player;

	if (game->stop_render)
		return (0);
	player = game->player;
	if (player->has_changed)
	{
		render_background(game, create_rgb(0, 0, 0));
		render_player(game);
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
			game->test_tex->img_ptr, 100, 100);
	}
	return (0);
}

void	render_background(t_game *game, int colour)
{
	int		x;
	int		y;

	if (!game->background)
		return ;
	y = 0;
	while (y < game->data->height)
	{
		x = 0;
		while (x < game->data->width)
		{
			set_pixel_in_image(game->background, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		game->background->img_ptr, 0, 0);
}

void	render_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (!player)
		return ;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		player->current_image->img_ptr, player->position.x, player->position.y);
	player->has_changed = false;
}
