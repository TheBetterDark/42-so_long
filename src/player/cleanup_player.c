/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:21:25 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/26 14:43:19 by muabdi           ###   ########.fr       */
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

void	cleanup_sprites(t_player_sprites *sprites)
{
	if (!sprites)
		return ;
	clear_image((sprites->player_up)->step_1);
	clear_image(sprites->player_up->step_2);
	clear_image(sprites->player_up->step_3);
	clear_image(sprites->player_down->step_1);
	clear_image(sprites->player_down->step_2);
	clear_image(sprites->player_down->step_3);
	clear_image(sprites->player_left->step_1);
	clear_image(sprites->player_left->step_2);
	clear_image(sprites->player_left->step_3);
	clear_image(sprites->player_right->step_1);
	clear_image(sprites->player_right->step_2);
	clear_image(sprites->player_right->step_3);
	free(sprites->player_up);
	free(sprites->player_down);
	free(sprites->player_left);
	free(sprites->player_right);
	free(sprites);
}

void	cleanup_player(t_player *player)
{
	if (!player)
		return ;
	cleanup_events(player->events);
	cleanup_sprites(player->sprites);
	free(player);
}
