/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:05 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/02 23:49:30 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// Releated headers

# include "./utils.h"

// Enum declarations

typedef enum e_map_elements
{
	EMPTY = '0',
	WALL = '1',
	SPAWN = 'P',
	EXIT = 'E',
	COLLECTABLE = 'C'
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

typedef struct s_animation
{
	t_image					*step_1;
	t_image					*step_2;
	t_image					*step_3;
}							t_animation;

typedef struct s_player_sprites
{
	t_animation				*player_up;
	t_animation				*player_down;
	t_animation				*player_left;
	t_animation				*player_right;
}							t_player_sprites;

typedef struct s_player
{
	t_player_sprites		*sprites;
	t_event					*events[4];
	t_vector2				position;

	int						animation_step;
	bool					has_changed;
}							t_player;

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
