/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:13:04 by muabdi            #+#    #+#             */
/*   Updated: 2024/07/02 16:47:39 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static bool			**init_visited(t_map *map);
static t_vector2	*get_collectables(t_map *map);
static void			free_visited(t_map *map, bool **visited);
static bool			dfs(t_map *map, t_vector2 current, t_vector2 end,
						bool **visited);

bool	find_path(t_map *map, t_vector2 start, t_vector2 end)
{
	t_vector2	*collectables;
	bool		**visited;
	bool		result;
	int			i;

	collectables = get_collectables(map);
	if (!collectables)
		return (NULL);
	i = 0;
	while (i < map->collectable_count)
	{
		visited = init_visited(map);
		if (!visited)
			return (NULL);
		if (!dfs(map, start, collectables[i], visited))
			return (free_visited(map, visited), free(collectables), false);
		start = collectables[i];
		free_visited(map, visited);
		i++;
	}
	visited = init_visited(map);
	if (!visited)
		return (NULL);
	result = dfs(map, start, end, visited);
	return (free_visited(map, visited), free(collectables), result);
}

static bool	dfs(t_map *map, t_vector2 current, t_vector2 end, bool **visited)
{
	const int	dx[] = {0, 0, 1, -1};
	const int	dy[] = {1, -1, 0, 0};
	int			i;

	if (current.x < 0 || current.y < 0 || current.y >= map->rows
		|| current.x >= map->columns || visited[current.y][current.x]
		|| map->grid[current.y][current.x] == WALL)
		return (false);
	visited[current.y][current.x] = true;
	if (current.x == end.x && current.y == end.y)
		return (true);
	i = 0;
	while (i < 4)
	{
		if (dfs(map, (t_vector2){current.x + dx[i],
				current.y + dy[i]}, end, visited))
			return (true);
		i++;
	}
	return (false);
}

static bool	**init_visited(t_map *map)
{
	bool		**visited;
	t_vector2	current_pos;

	visited = malloc(sizeof(int *) * map->rows);
	if (!visited)
		return (NULL);
	current_pos.y = 0;
	while (current_pos.y < map->rows)
	{
		visited[current_pos.y] = malloc(sizeof(bool) * map->columns);
		if (!visited[current_pos.y])
			return (free_visited(map, visited), NULL);
		current_pos.x = 0;
		while (current_pos.x < map->columns)
		{
			visited[current_pos.y][current_pos.x] = false;
			current_pos.x++;
		}
		current_pos.y++;
	}
	return (visited);
}

static void	free_visited(t_map *map, bool **visited)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (visited[i])
			free(visited[i]);
		i++;
	}
	free(visited);
}

static t_vector2	*get_collectables(t_map *map)
{
	t_vector2	*collectables;
	t_vector2	current_pos;
	int			i;

	if (!map)
		return (NULL);
	collectables = malloc(sizeof(t_vector2) * map->collectable_count);
	if (!collectables)
		return (NULL);
	current_pos.y = 0;
	i = 0;
	while (current_pos.y < map->rows)
	{
		current_pos.x = 0;
		while (current_pos.x < map->columns)
		{
			if (map->grid[current_pos.y][current_pos.x] == COLLECTABLE)
				collectables[i++] = current_pos;
			current_pos.x++;
		}
		current_pos.y++;
	}
	return (collectables);
}
