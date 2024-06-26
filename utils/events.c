/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:42:52 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/23 01:09:04 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_event	*connect_event(int event_type, int key_code, void *f, t_data *data)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!event)
		return (NULL);
	event->event_type = event_type;
	event->key_code = key_code;
	event->f = f;
	data->event_connections = ft_realloc(data->event_connections,
			(data->event_count + 1) * sizeof(t_event *));
	data->event_connections[data->event_count] = event;
	data->event_count++;
	return (event);
}

int	on_key_event(int key_code, t_data *data)
{
	int	i;

	if (data == NULL || data->event_connections == NULL)
		return (-1);
	i = 0;
	while (i < data->event_count)
	{
		i++;
		if (data->event_connections[i - 1]->event_type != KEY_EVENT)
			continue ;
		if (data->event_connections[i - 1]->key_code != key_code)
			continue ;
		data->event_connections[i - 1]->f();
	}
	return (0);
}

int	on_mouse_event(int key_code, t_data *data)
{
	int	i;

	if (data == NULL || data->event_connections == NULL)
		return (-1);
	i = 0;
	while (i < data->event_count)
	{
		i++;
		if (data->event_connections[i - 1]->event_type != MOUSE_EVENT)
			continue ;
		if (data->event_connections[i - 1]->key_code != key_code)
			continue ;
		data->event_connections[i - 1]->f();
	}
	return (0);
}

void	free_events(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->event_count)
	{
		free_event(data->event_connections[i]);
		i++;
	}
	free(data->event_connections);
	data->event_connections = NULL;
	data->event_count = 0;
}

void	free_event(t_event *event)
{
	free(event);
	event = NULL;
}
