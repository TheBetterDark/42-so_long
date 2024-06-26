/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/28 23:16:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*render_background(t_game *game, int colour)
{
	t_image	*image;
	int		x;
	int		y;

	y = 0;
	image = create_image(game->data, game->data->width,
			game->data->height);
	game->background = image;
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
		image->img_ptr, 0, 0);
	return (image);
}

int	render_loop(t_game *game)
{
	t_player	*player;

	if (game->data->stop_loop)
		return (0);
	player = game->player;
	if (!player->sprite || player->asset_changed || player->position_changed)
	{
		render_background(game, create_rgb(0, 0, 0));
		render_player(game);
	}
	return (0);
}
