/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:29 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:31:21 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_read_map	*map_sizes;
	char		*map;
	int			map_o;

	if (argc != 2 || argv[1] == NULL || *argv[1] == '\0')
		exit(1);
	map_sizes = ft_calloc(sizeof(t_read_map), 1);
	map_sizes->epos_x = -1;
	map_sizes->epos_y = -1;
	map_sizes->ppos_x = -1;
	map_sizes->ppos_y = -1;
	map_sizes->collectible_count = 0;
	map_sizes->caught_collectible = 0;
	map_sizes->playable = true;
	map = argv[1];
	map_o = open(map, O_RDONLY);
	get_map(map_o, map_sizes);
	close(map_o);
}

void	get_map(int map_o, t_read_map	*map_sizes)
{
	char	*map_read;
	char	*buffer;

	buffer = ft_calloc(2, sizeof(char));
	map_read = ft_calloc(1, sizeof(char));
	while ((read(map_o, buffer, 1)) == 1)
		map_read = ft_strjoin(map_read, buffer);
	free(buffer);
	map_sizes->map_lines = ft_split(map_read, '\n');
	map_sizes->map_copy = ft_split(map_read, '\n');
	map_sizes->screen_x = ft_strlen(map_sizes->map_lines[0]);
	map_sizes->screen_y = count_y(map_read, '\n');
	free(map_read);
	map_sizes = check_map(map_sizes);
	map_sizes->mlx = mlx_init((map_sizes->screen_x * 75), \
	(map_sizes->screen_y * 75), "so_long", true);
	textures(map_sizes);
	images(map_sizes);
	alloc_collectibles(map_sizes);
	create_screen(map_sizes);
	mlx_key_hook(map_sizes->mlx, &play_game, map_sizes);
	mlx_loop(map_sizes->mlx);
	finish(map_sizes);
	free (map_sizes);
}

t_read_map	*check_map(t_read_map *map_sizes)
{
	map_sizes->x = 0;
	map_sizes->y = 0;
	while (map_sizes->y < map_sizes->screen_y)
	{
		while (map_sizes->map_lines[map_sizes->y][map_sizes->x] != '\0')
		{
			check_dimensions(map_sizes);
			check_elements(map_sizes);
			map_sizes->x++;
		}
		if (map_sizes->x != map_sizes->screen_x)
			quit(map_sizes);
		map_sizes->x = 0;
		map_sizes->y++;
	}
	if (check_paths(map_sizes) == 1)
		quit(map_sizes);
	check_finals(map_sizes);
	return (map_sizes);
}

void	create_screen(t_read_map *map_sizes)
{
	map_sizes->x = 0;
	map_sizes->y = 0;
	map_sizes->i = 0;
	while (map_sizes->y < map_sizes->screen_y)
	{
		while (map_sizes->x < map_sizes->screen_x)
		{
			if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == '1')
				put_wall(map_sizes, map_sizes->x, map_sizes->y);
			if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == '0'
				|| map_sizes->map_lines[map_sizes->y][map_sizes->x] == 'P')
				put_free_way(map_sizes, map_sizes->x, map_sizes->y);
			if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == 'C')
				put_collectible(map_sizes, map_sizes->x, map_sizes->y);
			if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == 'B')
				put_blackhole(map_sizes, map_sizes->x, map_sizes->y);
			if (map_sizes->map_lines[map_sizes->y][map_sizes->x] == 'E')
				put_exit(map_sizes, map_sizes->x, map_sizes->y);
			map_sizes->x++;
		}
		map_sizes->x = 0;
		map_sizes->y++;
	}
	put_astro(map_sizes);
}

void	play_game(mlx_key_data_t keydata, void *map)
{
	t_read_map	*map_sizes;

	map_sizes = (t_read_map *) map;
	if (map_sizes->playable == true)
	{
		if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			&& keydata.action == MLX_PRESS)
			astro_move_up(map_sizes);
		if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			&& keydata.action == MLX_PRESS)
			astro_move_down(map_sizes);
		if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			&& keydata.action == MLX_PRESS)
			astro_move_left(map_sizes);
		if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			&& keydata.action == MLX_PRESS)
			astro_move_right(map_sizes);
		element_check(map_sizes);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		finish(map_sizes);
}
