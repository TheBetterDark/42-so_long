/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:37:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/22 18:21:16 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Structs
typedef struct s_image
{
	void			*img_ptr;
	char			*addr;
	int				h;
	int				w;
	int				bpp;
	int				endian;
	int				line_len;
}					t_image;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	int				img_count;
	t_image			**img_ptrs;
}					t_mlx;

// Window
t_mlx		*open_window(int width, int height, char *title);
int			close_window(t_mlx *mlx);

// Render
t_image		*render_background(t_mlx *mlx, int colour);

// Images
void		set_pixel_in_image(t_image *img, int x, int y, int color);
t_image		*create_image(t_mlx *mlx, int w, int h);
void		free_image(t_mlx *mlx, t_image *img);
void		free_images(t_mlx *mlx);

// Color
int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);

#endif
