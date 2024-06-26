/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:15:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/06 20:21:40 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_background(t_game *game, int colour)
{
	int		x;
	int		y;

	if (!game->background)
		game->background = create_image(game->data, game->data->width,
				game->data->height);
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
