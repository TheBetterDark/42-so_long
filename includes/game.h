/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:05 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/23 17:56:44 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// Enum declarations

// Macro declarations

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define MOUSE_BUTTON_1 1

// Struct declarations

// Function declarations

void		escape_pressed(void);
void		w_pressed(void);
void		s_pressed(void);
void		a_pressed(void);
void		d_pressed(void);
void		mouse_one_pressed(int x, int y);

#endif