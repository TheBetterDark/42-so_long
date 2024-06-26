/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:42:52 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/27 15:47:16 by muabdi           ###   ########.fr       */
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
	if (event_type == MOUSE_EVENT)
		event->f_mouse = f;
	else
		event->f_key = f;
	ft_lstadd_back(&data->event_connections, ft_lstnew(event));
	return (event);
}

int	on_key_event(int key_code, t_data *data)
{
	t_event	*current_event;
	t_list	*current_node;

	if (data == NULL || data->event_connections == NULL)
		return (-1);
	current_node = data->event_connections;
	while (current_node != NULL)
	{
		current_event = current_node->content;
		if (current_event->event_type == KEY_EVENT
			&& current_event->key_code == key_code)
			current_event->f_key();
		current_node = current_node->next;
	}
	return (0);
}

int	on_mouse_event(int key_code, int x, int y, t_data *data)
{
	t_event	*current_event;
	t_list	*current_node;

	if (data == NULL || data->event_connections == NULL)
		return (-1);
	current_node = data->event_connections;
	while (current_node != NULL)
	{
		current_event = current_node->content;
		if (current_event->event_type == MOUSE_EVENT
			&& current_event->key_code == key_code)
			current_event->f_mouse(x, y);
		current_node = current_node->next;
	}
	return (0);
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
