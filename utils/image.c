/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:13:02 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/21 19:26:35 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*create_image(t_data *data, int w, int h)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(data->mlx_ptr, w, h);
	if (!img->img_ptr)
		return (close_window(data), NULL);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	img->height = h;
	img->width = w;
	data->img_ptrs = ft_realloc(data->img_ptrs,
			(data->img_count + 1) * sizeof(t_image *));
	data->img_ptrs[data->img_count] = img;
	data->img_count++;
	return (img);
}

void	set_pixel_in_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	free_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->img_count)
	{
		free_image(data, data->img_ptrs[i]);
		i++;
	}
	free(data->img_ptrs);
	data->img_ptrs = NULL;
	data->img_count = 0;
}

void	free_image(t_data *data, t_image *img)
{
	mlx_destroy_image(data->mlx_ptr, img->img_ptr);
	free(img);
	img = NULL;
}
