/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:48:23 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/13 14:51:49 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	validate_map_borders(t_map *map);
static bool	validate_map_components(t_map *map);
static bool	validate_map_path(t_map *map);
static bool	validate_map_size(t_map *map);

bool	validate_map_grid(t_map *map)
{
	if (validate_map_borders(map) == false)
		return (false);
	if (validate_map_components(map) == false)
		return (false);
	if (validate_map_path(map) == false)
		return (false);
	if (validate_map_size(map) == false)
		return (false);
	return (true);
}

static bool	validate_map_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i > map->columns
		&& (map->grid[0][i] != '\n' && map->grid[map->rows][i] != '\n'))
	{
		if (map->grid[0][i] != WALL || map->grid[map->rows][i] != WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->rows
		&& (map->grid[i][0] != '\n' && map->grid[i][map->columns] != '\n'))
	{
		if (map->grid[i][0] != WALL || map->grid[i][map->columns] != WALL)
			return (false);
		i++;
	}
	return (true);
}

static bool	validate_map_components(t_map *map)
{
	(void)map;
	return (true);
}

static bool	validate_map_path(t_map *map)
{
	(void)map;
	return (true);
}

static bool	validate_map_size(t_map *map)
{
	(void)map;
	return (true);
}
