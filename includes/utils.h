/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:37:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 00:52:58 by muabdi           ###   ########.fr       */
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

# define MOUSE_EVENT 1
# define KEY_EVENT 0

// Struct declarations

typedef struct s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct s_color3
{
	int				r;
	int				g;
	int				b;
	int				hex;
}					t_color3;

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

typedef struct s_sprite
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
}					t_sprite;

typedef struct s_event
{
	int				event_type; // 0 = Keyboard | 1 = Mouse
	int				key_code;
	void			(*f_mouse)(int x, int y);
	void			(*f_key)(void); // TODO: Make into variadic function
}					t_event;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;

	t_list			*event_connections;
	t_list			*animations;
	t_list			*img_ptrs;
	t_list			*tex_ptrs;
}					t_data;

// Function declarations

t_data		*open_window(int width, int height, char *title);
int			close_window(t_data *data);

t_image		*render_background(t_data *data, int colour);

t_image		*create_image(t_data *data, int w, int h);
void		set_pixel_in_image(t_image *img, int x, int y, int color);
void		free_images(t_data *data);
void		*free_image(t_image *img);

t_sprite	*create_sprite(t_data *data, char *file_name);
void		free_sprites(t_data *data);
void		*free_sprite(t_sprite *tex);

t_event		*connect_event(int event_type, int key_code, void *f, t_data *data);
int			on_mouse_event(int key_code, int x, int y, t_data *data);
int			on_key_event(int key_code, t_data *data);
void		*free_event(t_event *event);
void		free_events(t_data *data);

int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);

#endif
