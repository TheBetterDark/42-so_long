/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:44:11 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/23 00:50:15 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the main header file for the so_long project.
** It includes all the necessary headers for the project.
*/

#ifndef SO_LONG_H
# define SO_LONG_H

// Standard C Libraries
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// External Libraries
# include "libft.h"
# include "mlx.h"

// Custom Headers
# include "utils.h"
# include "game.h"

// TEST FUNCTIONS
void	escape_pressed(void);
void	w_pressed(void);
void	s_pressed(void);
void	a_pressed(void);
void	d_pressed(void);

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

#endif
