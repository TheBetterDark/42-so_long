/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:37:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/28 22:12:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Related headers

# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>

// Enum declarations

// Macro declarations

// Struct declarations

typedef struct s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct s_image
{
	void			*mlx_ptr;
	void			*win_ptr;

	void			*img_ptr;
	char			*addr;

	int				height;
	int				width;

	int				bpp;
	int				endian;
	int				line_len;
}					t_image;

typedef struct s_texture
{
	void			*mlx_ptr;
	void			*win_ptr;

	void			*xpm_ptr;
	char			*addr;

	int				height;
	int				width;

	int				bpp;
	int				endian;
	int				line_len;
}					t_texture;

typedef struct s_event
{
	int				key_code;
	void			(*f)(int key_code);
}					t_event;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;

	bool			stop_loop;

	t_list			*event_connections;
	t_list			*texture_ptrs;
	t_list			*img_ptrs;
}					t_data;

// Function declarations

t_data		*open_window(int width, int height, char *title);
int			close_window(t_data *data);

t_image		*create_image(t_data *data, int w, int h);
void		set_pixel_in_image(t_image *img, int x, int y, int color);
void		free_images(t_data *data);
void		*free_image(t_image *img);

t_texture	*create_texture(t_data *data, char *file_name, t_vector2 position);
void		*free_texture(t_texture *texture);
void		free_textures(t_data *data);

t_event		*connect_event(int key_code, void *f, t_data *data);
void		*free_event(t_event *event);
void		free_events(t_data *data);

int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);

#endif
