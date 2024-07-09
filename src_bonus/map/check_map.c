/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:48:23 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/08 12:45:49 by muabdi           ###   ########.fr       */
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

bool	validate_map_components(t_map *map, t_vector2 pos)
{
	pos.y = 0;
	while (pos.y < map->rows)
	{
		pos.x = 0;
		while (pos.x < map->columns)
		{
			if (map->grid[pos.y][pos.x] == COLLECTABLE)
				map->collectable_count++;
			else if (map->grid[pos.y][pos.x] == SPAWN)
				map->spawn_count++;
			else if (map->grid[pos.y][pos.x] == EXIT)
				map->exit_count++;
			else if (map->grid[pos.y][pos.x] != MAP_BLINKY
				&& map->grid[pos.y][pos.x] != MAP_CLYDE
				&& map->grid[pos.y][pos.x] != MAP_INKY
				&& map->grid[pos.y][pos.x] != MAP_PINKY
				&& map->grid[pos.y][pos.x] != WALL
				&& map->grid[pos.y][pos.x] != EMPTY)
				return (false);
			pos.x++;
		}
		pos.y++;
	}
	return (map->collectable_count >= 1 && map->exit_count == 1
		&& map->spawn_count == 1);
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
	t_vector2	pos;

	pos.y = 0;
	while (pos.y < map->rows)
	{
		pos.x = 0;
		while (pos.x < map->columns)
		{
			if (map->grid[pos.y][pos.x] == SPAWN)
				map->spawn_pos = pos;
			else if (map->grid[pos.y][pos.x] == EXIT)
				map->exit_pos = pos;
			else if (map->grid[pos.y][pos.x] == MAP_BLINKY)
				map->blinky_pos = pos;
			else if (map->grid[pos.y][pos.x] == MAP_CLYDE)
				map->clyde_pos = pos;
			else if (map->grid[pos.y][pos.x] == MAP_INKY)
				map->inky_pos = pos;
			else if (map->grid[pos.y][pos.x] == MAP_PINKY)
				map->pinky_pos = pos;
			pos.x++;
		}
		pos.y++;
	}
	return (map);
}
