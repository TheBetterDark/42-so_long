/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:37:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/04 15:00:20 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Standard Library headers

# include <stdbool.h>
# include <stdlib.h>

// Releated headers

# include "../libs/minilibx-linux/mlx.h"

// Struct declarations

typedef struct s_vector2
{
	int		x;
	int		y;
}			t_vector2;

typedef struct s_bounding_box
{
	int		x;
	int		y;

	int		height;
	int		width;
}			t_bounding_box;

typedef struct s_image
{
	void	*mlx_ptr;

	void	*img_ptr;
	char	*addr;

	int		height;
	int		width;

	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_event
{
	void	(*event_handler)(int key_code, void *data);
	int		key_code;
}			t_event;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_data;

// Function declarations

t_data		*open_window(int width, int height, char *title);
int			close_window(t_data *data);

t_image		*create_image(t_data *data, int w, int h);
t_image		*load_texture(t_data *data, char *file_name);
void		set_pixel_in_image(t_image *img, int x, int y, int color);
void		clear_image(t_image *img);

t_event		*connect_event(int key_code, void *f);
void		disconnect_event(t_event *event);

bool		check_bounding_box(t_bounding_box a, t_bounding_box b);

int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);

int			open_file(char *file_path);
int			close_file(int fd);

#endif
