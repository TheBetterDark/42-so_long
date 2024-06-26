/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:05 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/28 21:58:13 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// Enum declarations

typedef enum e_map_elements
{
	exit_position = 'E',
	player_spawn = 'P',
	collectible = 'C',
	empty = '0',
	wall = '1'
}	t_map_elements;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

// Macro declarations

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// Struct declarations

typedef struct s_player
{
	t_texture		*sprite;
	t_event			*events[4];

	bool			position_changed;
	t_vector2		position;

	bool			asset_changed;
	char			*asset;

	int				anim_step;
}					t_player;

typedef struct s_game
{
	t_data			*data;
	t_player		*player;
	t_image			*background;
	void			*map;

	bool			stop_render;
}					t_game;

// Function declarations

t_player	*create_player(t_game *game, t_vector2 spawn_pos);
void		animate_player(t_player *player, t_direction direction);
void		render_player(t_game *game);

void		*player_move_up(int key_code, t_game *game);
void		*player_move_down(int key_code, t_game *game);
void		*player_move_left(int key_code, t_game *game);
void		*player_move_right(int key_code, t_game *game);

t_image		*render_background(t_game *game, int colour);
int			render_loop(t_game *game);

#endif