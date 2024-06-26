/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:42:52 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/26 14:37:52 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_event	*connect_event(int key_code, void *f)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!event)
		return (NULL);
	event->key_code = key_code;
	event->event_handler = f;
	return (event);
}

void	disconnect_event(t_event *event)
{
	if (!event)
		return ;
	free(event);
}
