/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:42:52 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/27 18:08:21 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_event	*connect_event(int key_code, void *f, t_data *data)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!event)
		return (NULL);
	event->key_code = key_code;
	event->f = f;
	ft_lstadd_back(&data->event_connections, ft_lstnew(event));
	return (event);
}

void	free_events(t_data *data)
{
	ft_lstclear(&data->event_connections, (void *)free_event);
	data->event_connections = NULL;
}

void	*free_event(t_event *event)
{
	free(event);
	event = NULL;
	return (NULL);
}
