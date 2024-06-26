/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:56:09 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 00:21:09 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*create_sprite(t_data *data, char *file_name)
{
	t_sprite	*tex;

	tex = malloc(sizeof(t_sprite));
	if (!tex)
		return (NULL);
	tex->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, file_name, &tex->width,
			&tex->height);
	if (!tex->xpm_ptr)
		return (close_window(data), NULL);
	tex->addr = mlx_get_data_addr(tex->xpm_ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
	tex->mlx_ptr = data->mlx_ptr;
	tex->win_ptr = data->win_ptr;
	ft_lstadd_back(&data->tex_ptrs, ft_lstnew(tex));
	return (tex);
}

void	free_sprites(t_data *data)
{
	ft_lstclear(&data->tex_ptrs, (void *)free_sprite);
	data->tex_ptrs = NULL;
}

void	*free_sprite(t_sprite *tex)
{
	if (tex->xpm_ptr)
		mlx_destroy_image(tex->mlx_ptr, tex->xpm_ptr);
	free(tex);
	tex = NULL;
	return (NULL);
}
