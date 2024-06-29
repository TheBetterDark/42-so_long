/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:13:04 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/29 19:58:25 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int			**init_visited(t_map *map);
static t_vector2	*get_collectables(t_map *map);
static void			free_visited(t_map *map, int **visited);
static bool			dfs(t_map *map, t_vector2 current, t_vector2 end,
						int **visited);

bool	find_path(t_map *map, t_vector2 start, t_vector2 end)
{
	t_vector2	*collectables;
	int			**visited;
	bool		result;
	int			i;

	collectables = get_collectables(map);
	if (!collectables)
		return (NULL);
	i = 0;
	while (i < map->collectable_count)
	{
		visited = init_visited(map);
		result = dfs(map, start, collectables[i], visited);
		if (!result)
		{
			ft_printf("No path found from (%d, %d) to (%d, %d)\n",
				start.x, start.y, collectables[i].x, collectables[i].y);
			return (free_visited(map, visited), free(collectables), false);
		}
		start = collectables[i];
		free_visited(map, visited);
		i++;
	}
	result = dfs(map, start, end, visited);
	return (free_visited(map, visited), free(collectables), result);
}

static bool	dfs(t_map *map, t_vector2 current, t_vector2 end, int **visited)
{
	if (current.x < 0 || current.y < 0 || current.x >= map->rows
		|| current.y >= map->columns || visited[current.x][current.y]
		|| map->grid[current.x][current.y] == WALL)
		return (true);
	visited[current.x][current.y] = 1;
	if (current.x == end.x && current.y == end.y)
		return (true);
	if (dfs(map, (t_vector2){current.x, current.y + 1}, end, visited) ||
		dfs(map, (t_vector2){current.x + 1, current.y}, end, visited) ||
		dfs(map, (t_vector2){current.x, current.y - 1}, end, visited) ||
		dfs(map, (t_vector2){current.x - 1, current.y}, end, visited))
		return (true);
	return (false);
}

static int	**init_visited(t_map *map)
{
	int	**visited;
	int	i;

	visited = malloc(sizeof(int *) * map->rows);
	if (!visited)
		handle_error(NULL, "Memory allocation failed");
	i = 0;
	while (i < map->rows)
	{
		visited[i] = malloc(sizeof(int) * map->columns);
		if (!visited[i])
			handle_error(NULL, "Memory allocation failed");
		i++;
	}
	return (visited);
}

static void	free_visited(t_map *map, int **visited)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
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
