/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:16:35 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:48:32 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	open_window(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

int	close_window(t_window *mlx_window)
{
	if (mlx_window)
	{
		mlx_destroy_window(mlx_window->mlx_ptr, mlx_window->win_ptr);
		mlx_destroy_display(mlx_window->mlx_ptr);
		free(mlx_window->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}
