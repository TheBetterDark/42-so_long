/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:05 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/29 19:50:15 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// Standard library headers

# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>

// External libraries

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"

// Related headers

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

# define PLAYER_SPEED 8

# define TILE_SIZE 64 // 64px

// Struct declarations

typedef struct s_animation
{
	t_image					*step_1;
	t_image					*step_2;
	t_image					*step_3;
}							t_animation;

typedef struct s_tile
{
	t_image					*sprite;
	t_vector2				position;
}							t_tile;

typedef struct s_map
{
	char					**grid;
	int						rows;
	int						columns;

	int						collectable_count;
	t_vector2				spawn_pos;
	t_vector2				exit_pos;

	t_list					*empty_tiles;
	t_list					*wall_tiles;
	t_list					*collectable_tiles;
	t_list					*exit_tiles;
}							t_map;

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
	int						move_count;
	bool					has_changed;
}							t_player;

typedef struct s_game
{
	t_data					*data;
	t_player				*player;
	t_image					*background;
	t_map					*map;

	t_image					*test_tex;

	bool					stop_render;
}							t_game;

// Function declarations

t_game				*initalize_game(void);
int					handle_error(t_game *game, char *info);

t_map				*create_map_grid(char *file_path);
bool				validate_map_borders(t_map *map);
bool				validate_map_components(t_map *map);
bool				validate_map_path(t_map *map);
bool				validate_map_size(t_map *map);
bool				find_path(t_map *map, t_vector2 start, t_vector2 end);

t_player			*create_player(t_game *game, t_vector2 spawn_pos);
void				animate_player(t_player *player, t_animation *animation);
void				handle_player_event(int key_code, t_game *game);
t_player_sprites	*load_player_sprites(t_data *data);

bool				check_player_collisions(t_game *game, t_vector2 direction);

void				*player_move_up(int key_code, t_game *game);
void				*player_move_down(int key_code, t_game *game);
void				*player_move_left(int key_code, t_game *game);
void				*player_move_right(int key_code, t_game *game);

void				cleanup_sprites(t_player_sprites *sprites);
void				cleanup_events(t_event **events);
void				cleanup_player(t_player *player);
void				cleanup_map(t_map *map);

int					render_loop(t_game *game);

#endif
