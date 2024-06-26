/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:37:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/23 00:39:31 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// X11
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

// Structs
typedef struct s_image
{
	void			*img_ptr;
	char			*addr;

	int				height;
	int				width;

	int				bpp;
	int				endian;
	int				line_len;
}					t_image;

typedef struct s_event
{
	int				event_type; // 0 = Keyboard | 1 = Mouse
	int				key_code;
	void			(*f)(void);
}					t_event;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;

	t_image			**img_ptrs;
	int				img_count;

	t_event			**event_connections;
	int				event_count;
}					t_data;

// Window
t_data		*open_window(int width, int height, char *title);
int			close_window(t_data *data);

// Render
t_image		*render_background(t_data *data, int colour);

// Images
void		set_pixel_in_image(t_image *img, int x, int y, int color);
t_image		*create_image(t_data *data, int w, int h);
void		free_image(t_data *data, t_image *img);
void		free_images(t_data *data);

// Events
t_event		*connect_event(int event_type, int key_code, void *f, t_data *data);
int			on_mouse_event(int key_code, t_data *data);
int			on_key_event(int key_code, t_data *data);
void		free_events(t_data *data);
void		free_event(t_event *event);

// Color
int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);

# define KEY_EVENT 0
# define MOUSE_EVENT 1

#endif
