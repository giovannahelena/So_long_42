/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technicals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:10:23 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:29:58 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	count_y(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*s == c)
	{
		s++;
		if (!*s)
			return (count);
	}
	count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	finish(t_read_map	*map_sizes)
{
	int	i;

	i = 0;
	d_images(map_sizes);
	disalloc_collectibles(map_sizes);
	while (i < map_sizes->screen_y)
	{
		free(map_sizes->map_lines[i]);
		i++;
	}
	free(map_sizes->map_lines);
	i = 0;
	while (i < map_sizes->screen_y)
	{
		free(map_sizes->map_copy[i]);
		i++;
	}
	free(map_sizes->map_copy);
	mlx_close_window(map_sizes->mlx);
	mlx_terminate(map_sizes->mlx);
	free (map_sizes);
	exit(0);
}

void	quit(t_read_map *map_sizes)
{
	int	i;

	i = 0;
	while (i < map_sizes->screen_y)
		free(map_sizes->map_lines[i++]);
	free(map_sizes->map_lines);
	i = 0;
	while (i < map_sizes->screen_y)
		if (map_sizes->map_copy[i])
			free(map_sizes->map_copy[i++]);
	free(map_sizes->map_copy);
	free (map_sizes);
	exit(write(2, "Error\nSelect a valid map\n", 25));
}

void	alloc_collectibles(t_read_map *map_sizes)
{
	int	i;

	i = -1;
	map_sizes->colectibles_positions = ft_calloc \
	(map_sizes->collectible_count, sizeof(int *));
	while (++i < map_sizes->collectible_count)
		map_sizes->colectibles_positions[i] = ft_calloc(2, sizeof(int));
}

void	disalloc_collectibles(t_read_map *map_sizes)
{
	int	i;

	i = -1;
	while (++i < map_sizes->collectible_count)
		free(map_sizes->colectibles_positions[i]);
	free(map_sizes->colectibles_positions);
}
