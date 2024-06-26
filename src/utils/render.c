/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 00:37:02 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*render_background(t_data *data, int colour)
{
	t_image	*image;
	int		x;
	int		y;

	y = 0;
	image = create_image(data, data->width, data->height);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_pixel_in_image(image, x, y, colour);
			x++;
		}
		y++;
	}
	return (image);
}

// TODO: Rendering Animations

// TODO: Rendering Graphics
