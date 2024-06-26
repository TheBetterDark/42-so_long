/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:55:45 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/26 23:19:31 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static t_map	*allocate_map_grid(int fd);
static int		open_file(char *file_path);
static int		close_file(int fd);

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
	char	*line;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(line), NULL);
	map->grid = NULL;
	map->columns = ft_strlen(line) - 1;
	map->rows = 0;
	while (line)
	{
		map->grid = ft_realloc((void *)map->grid,
				sizeof(char *) * map->rows,
				sizeof(char *) * (map->rows + 1));
		map->grid[map->rows] = line;
		line = get_next_line(fd);
		map->rows++;
	}
	return (map);
}

static int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	return (fd);
}

static int	close_file(int fd)
{
	if (close(fd) < 0)
		return (-1);
	return (1);
}
