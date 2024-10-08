/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:29:53 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/04 15:04:47 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	handle_error(t_game *game, char *info)
{
	ft_printf("\033[0;31mError: %s\n\033[0;31m", info);
	if (!game)
		return (exit(EXIT_FAILURE), EXIT_FAILURE);
	cleanup_player(game->player);
	close_window(game->data);
	free(game);
	return (exit(EXIT_FAILURE), EXIT_FAILURE);
}
