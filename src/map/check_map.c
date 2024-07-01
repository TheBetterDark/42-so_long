/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:48:23 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/01 18:30:32 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static t_map	*find_start_end(t_map *map);

bool	validate_map_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->columns
		&& (map->grid[0][i] != '\n' && map->grid[map->rows - 1][i] != '\n'))
	{
		if (map->grid[0][i] != WALL || map->grid[map->rows - 1][i] != WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i][0] != WALL || (map->grid[i][map->columns - 1] != WALL
			&& map->grid[i][map->columns - 1] != '\n'))
			return (false);
		i++;
	}
	return (true);
}

bool	validate_map_components(t_map *map)
{
	int			spawn_count;
	int			exit_count;
	int			y;
	int			x;

	spawn_count = 0;
	exit_count = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->grid[y][x] == COLLECTABLE)
				map->collectable_count++;
			if (map->grid[y][x] == SPAWN)
				spawn_count++;
			if (map->grid[y][x] == EXIT)
				exit_count++;
			x++;
		}
		y++;
	}
	return (map->collectable_count >= 1 && exit_count == 1 && spawn_count == 1);
}

bool	validate_map_path(t_map *map)
{
	map = find_start_end(map);
	if (!map)
		return (false);
	if (!find_path(map, map->spawn_pos, map->exit_pos))
		return (false);
	return (true);
}

bool	validate_map_size(t_map *map)
{
	size_t	expected_length;
	int		y;

	if (map->rows <= 4 || map->columns <= 2)
		return (false);
	expected_length = map->columns;
	y = 0;
	while (y < map->rows)
	{
		if ((ft_strlen(map->grid[y]) - 1) != expected_length)
			return (false);
		y++;
	}
	return (true);
}

static t_map	*find_start_end(t_map *map)
{
	t_vector2	current_pos;

	current_pos.y = 0;
	while (current_pos.y < map->rows)
	{
		current_pos.x = 0;
		while (current_pos.x < map->columns)
		{
			if (map->grid[current_pos.y][current_pos.x] == SPAWN)
				map->spawn_pos = (t_vector2){current_pos.x, current_pos.y};
			if (map->grid[current_pos.y][current_pos.x] == EXIT)
				map->exit_pos = (t_vector2){current_pos.x, current_pos.y};
			current_pos.x++;
		}
		current_pos.y++;
	}
	return (map);
}
