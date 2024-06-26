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

t_image	*create_image(t_mlx *mlx, int w, int h)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, w, h);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	img->h = h;
	img->w = w;
	mlx->img_ptrs = ft_realloc(mlx->img_ptrs, (mlx->img_count + 1)
			* sizeof(void *));
	mlx->img_ptrs[mlx->img_count] = img;
	mlx->img_count++;
	return (img);
}

void	set_pixel_in_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	free_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->img_count)
	{
		free_image(mlx, mlx->img_ptrs[i]);
		i++;
	}
	free(mlx->img_ptrs);
	mlx->img_ptrs = NULL;
	mlx->img_count = 0;
}

void	free_image(t_mlx *mlx, t_image *img)
{
	mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	free(img);
	img = NULL;
}
