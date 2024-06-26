/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:29:53 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/07 20:34:49 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_error(t_game *game, char *info)
{
	ft_printf("Error:\n %c\n", info);
	if (!game)
		return (exit(EXIT_FAILURE), EXIT_FAILURE);
	cleanup_player(game->player);
	close_window(game->data);
	free(game);
	return (exit(EXIT_FAILURE), EXIT_FAILURE);
}
