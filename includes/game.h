/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:05 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 04:54:15 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// Enum declarations

enum e_map_elements
{
	exit_position = 'E',
	player_spawn = 'P',
	collectible = 'C',
	empty = '0',
	wall = '1'
};

// Macro declarations

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define MOUSE_BUTTON_1 1

// Struct declarations

typedef struct s_character
{
	t_texture		*texture;
	t_vector2		*position;
	t_event			*events;
	t_animation		*animation;
}					t_character;

typedef struct s_player
{
	t_character		*character_body;
}					t_player;

typedef struct s_enemy
{
	t_character		*character_body;
}					t_enemy;

typedef struct s_game
{
	t_data			*data;
	t_player		*player;
}					t_game;

// Function declarations

#endif