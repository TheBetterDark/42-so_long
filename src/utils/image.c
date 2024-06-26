/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:42:12 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/27 15:47:19 by muabdi           ###   ########.fr       */
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
	img->mlx_ptr = data->mlx_ptr;
	img->win_ptr = data->win_ptr;
	ft_lstadd_back(&data->img_ptrs, ft_lstnew(img));
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
	ft_lstclear(&data->img_ptrs, (void *)free_image);
	data->img_ptrs = NULL;
}

void	*free_image(t_image *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
	img = NULL;
	return (NULL);
}
