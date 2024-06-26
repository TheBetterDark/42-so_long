/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:42:12 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/07 20:27:12 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_image	*create_image(t_data *data, int width, int height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->mlx_ptr = data->mlx_ptr;
	img->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!img->img_ptr)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

t_image	*load_texture(t_data *data, char *file_name)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->mlx_ptr = data->mlx_ptr;
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, file_name,
			&img->width, &img->height);
	if (!img->img_ptr)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
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

void	clear_image(t_image *img)
{
	if (!img)
		return ;
	if (img->img_ptr)
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
	img = NULL;
}
