/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:28:42 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:40:35 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_window;

t_window	open_window(int w, int h, char *str);
int			close_window(t_window *mlx_window);

#endif
