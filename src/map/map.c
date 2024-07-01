/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:55:45 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/29 20:06:32 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static t_map	*allocate_map_grid(int fd);
static t_map	*read_map(t_map *map, int fd);
static bool		validate_map_grid(t_map *map);

t_map	*create_map_grid(char *file_path)
{
	t_map	*map;
	int		fd;

	fd = open_file(file_path);
	if (fd < 0)
		handle_error(NULL, "Unable to open file");
	map = allocate_map_grid(fd);
	if (!map)
		handle_error(NULL, "Unable to allocate map grid");
	if (!validate_map_grid(map))
	{
		cleanup_map(map);
		handle_error(NULL, "Invalid map");
	}
	if (close_file(fd) < 0)
	{
		cleanup_map(map);
		handle_error(NULL, "Unable to close file");
	}
	return (map);
}

void	cleanup_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

static t_map	*allocate_map_grid(int fd)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map = read_map(map, fd);
	if (!map)
		return (NULL);
	map->collectable_count = 0;
	map->spawn_pos = (t_vector2){-1, -1};
	map->exit_pos = (t_vector2){-1, -1};
	return (map);
}

static t_map	*read_map(t_map *map, int fd)
{
	char	*line;

	if (!map || fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(line), NULL);
	map->columns = ft_strlen(line) - 1;
	map->rows = 0;
	map->grid = NULL;
	while (line)
	{
		map->grid = ft_realloc((void *)map->grid,
				sizeof(char *) * map->rows,
				sizeof(char *) * (map->rows + 1));
		if (!map->grid)
			return (free(map), NULL);
		map->grid[map->rows] = line;
		line = get_next_line(fd);
		map->rows++;
	}
	return (map);
}

static bool	validate_map_grid(t_map *map)
{
	if (!validate_map_borders(map))
		return (false);
	if (!validate_map_components(map))
		return (false);
	if (!validate_map_size(map))
		return (false);
	if (!validate_map_path(map))
		return (false);
	return (true);
}
