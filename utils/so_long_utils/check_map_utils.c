/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:52:13 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:27 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	check_dimensions(t_read_map	*map_sizes)
{
	if (map_sizes->map_lines[map_sizes->y][map_sizes->x] != 49
		&& (map_sizes->y == 0 || map_sizes->x == 0
		|| map_sizes->y == map_sizes->screen_y - 1
		|| map_sizes->x == map_sizes->screen_x - 1))
		quit(map_sizes);
	if (map_sizes->map_lines[map_sizes->y][map_sizes->x] != 48
		&& map_sizes->map_lines[map_sizes->y][map_sizes->x] != 49
		&& map_sizes->map_lines[map_sizes->y][map_sizes->x] != 67
		&& map_sizes->map_lines[map_sizes->y][map_sizes->x] != 69
		&& map_sizes->map_lines[map_sizes->y][map_sizes->x] != 80
		&& map_sizes->map_lines[map_sizes->y][map_sizes->x] != 66)
		quit(map_sizes);
}

int	check_paths(t_read_map *map_sizes)
{
	int	x;
	int	y;

	x = map_sizes->ppos_x;
	y = map_sizes->ppos_y;
	map_sizes->map_copy = flood_fill(map_sizes->map_copy, y, x);
	x = 0;
	y = 0;
	while (y < map_sizes->screen_y)
	{
		while (x < map_sizes->screen_x)
		{
			if (map_sizes->map_copy[y][x] != 'X' && \
				map_sizes->map_copy[y][x] != '1' && \
				map_sizes->map_copy[y][x] != 'B' && \
				map_sizes->map_copy[y][x] != '0')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char	**flood_fill(char **map_copy, int y, int x)
{
	if (map_copy[y][x] == '0' || map_copy[y][x] == 'P' || \
		map_copy[y][x] == 'E' || map_copy[y][x] == 'B' || \
		map_copy[y][x] == 'C')
	{
		map_copy[y][x] = 'X';
		map_copy = flood_fill(map_copy, y - 1, x);
		map_copy = flood_fill(map_copy, y + 1, x);
		map_copy = flood_fill(map_copy, y, x - 1);
		map_copy = flood_fill(map_copy, y, x + 1);
	}
	return (map_copy);
}

void	check_elements(t_read_map	*map_sizes)
{
	if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == 80)
	{
		if (map_sizes->ppos_x != -1 || map_sizes->ppos_y != -1)
			quit(map_sizes);
		map_sizes->ppos_x = map_sizes->x;
		map_sizes->ppos_y = map_sizes->y;
	}
	if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == 69)
	{
		if (map_sizes->epos_x != -1 || map_sizes->epos_y != -1)
			quit(map_sizes);
		map_sizes->epos_x = map_sizes->x;
		map_sizes->epos_y = map_sizes->y;
	}
	if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == 67)
		map_sizes->collectible_count++;
}

void	check_finals(t_read_map	*map_sizes)
{
	if (map_sizes->ppos_x < 1 || map_sizes->ppos_y < 1
		|| map_sizes->epos_x < 1 || map_sizes->epos_y < 1
		|| map_sizes->collectible_count < 1)
		quit(map_sizes);
	if (map_sizes->y != map_sizes->screen_y)
		quit(map_sizes);
}
