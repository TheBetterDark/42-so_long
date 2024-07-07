/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:21:25 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/07 18:39:55 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	cleanup_events(t_event **events)
{
	disconnect_event(events[0]);
	disconnect_event(events[1]);
	disconnect_event(events[2]);
	disconnect_event(events[3]);
}

void	cleanup_player(t_player *player)
{
	if (!player)
		return ;
	cleanup_events(player->events);
	clear_image(player->current_image);
	free(player);
}
