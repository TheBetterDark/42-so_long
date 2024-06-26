/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:14:58 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/27 15:47:28 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_animation	*create_animation(t_data *data, bool looping)
{
	t_animation	*animation;

	animation = malloc(sizeof(t_animation));
	if (!animation)
		return (NULL);
	animation->frames = NULL;
	ft_lstadd_back(&data->animations, ft_lstnew(animation));
	return (animation);
}

void	add_frame(t_animation *animation, t_image *frame)
{
	t_list	*new_frame;

	new_frame = ft_lstnew(frame);
	if (!new_frame)
		return ;
	ft_lstadd_back(&animation->frames, new_frame);
}

void	destory_animations(t_data *data)
{
	ft_lstclear(&data->animations, (void *)destroy_animation);
	data->animations = NULL;
}

void	*destroy_animation(t_animation *animation)
{
	t_list	*frame;
	t_list	*next_frame;

	frame = animation->frames;
	while (frame)
	{
		next_frame = frame->next;
		free(frame->content);
		free(frame);
		frame = next_frame;
	}
	free(animation);
	return (NULL);
}
