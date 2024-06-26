/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:05 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/07 20:17:18 by muabdi           ###   ########.fr       */
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
	t_image					*current_image;
	t_player_sprites		*sprites;
	t_event					*events[4];
	t_vector2				position;

	int						animation_step;
	bool					has_changed;
}							t_player;

typedef struct s_game
{
	t_data					*data;
	t_player				*player;
	t_image					*background;
	char					**map;

	bool					stop_render;
}					t_game;

// Function declarations

t_game				*initalize_game(void *f);

t_player			*create_player(t_game *game, t_vector2 spawn_pos);
void				animate_player(t_player *player, t_animation *animation);
void				handle_player_event(int key_code, t_game *game);
t_player_sprites	*load_player_sprites(t_data *data);
void				render_player(t_game *game);

void				*player_move_up(int key_code, t_game *game);
void				*player_move_down(int key_code, t_game *game);
void				*player_move_left(int key_code, t_game *game);
void				*player_move_right(int key_code, t_game *game);

void				cleanup_events(t_event **events);
void				cleanup_sprites(t_player_sprites *sprites);
void				cleanup_player(t_player *player);

void				render_background(t_game *game, int colour);
int					render_loop(t_game *game);

#endif
