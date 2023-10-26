/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:25:30 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:15 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	element_check(void *map)
{
	t_read_map	*map_sizes;

	map_sizes = (t_read_map *) map;
	if (map_sizes->map_lines[map_sizes->ppos_y][map_sizes->ppos_x] == 66)
		black_hole(map_sizes);
	if (map_sizes->map_lines[map_sizes->ppos_y][map_sizes->ppos_x] == 67)
		catch_star(map_sizes);
	if (map_sizes->map_lines[map_sizes->ppos_y][map_sizes->ppos_x] == 69)
		win_check(map_sizes);
}

void	catch_star(t_read_map *map_sizes)
{
	int	i;

	i = 0;
	map_sizes->map_lines[map_sizes->ppos_y][map_sizes->ppos_x] = 48;
	map_sizes->caught_collectible++;
	while (i < map_sizes->collectible_count)
	{
		if (map_sizes->ppos_x == map_sizes->colectibles_positions[i][0] &&
			map_sizes->ppos_y == map_sizes->colectibles_positions[i][1])
			map_sizes->elements.star_img->instances[i].enabled = false;
		i++;
	}
}

void	disp_info(t_read_map *map_sizes)
{
	char	*moves;
	char	*stars_total;
	char	*stars_collected;

	moves = ft_itoa(map_sizes->move_count);
	stars_total = ft_itoa(map_sizes->collectible_count);
	stars_collected = ft_itoa(map_sizes->caught_collectible);
	mlx_image_to_window(map_sizes->mlx, \
	map_sizes->elements.frame_image, 0, 0);
	ft_printf("Moves: %i\n", map_sizes->move_count);
	mlx_put_string(map_sizes->mlx, "Moves: ", 0, 0);
	mlx_put_string(map_sizes->mlx, moves, 75, 0);
	mlx_put_string(map_sizes->mlx, "Stars: ", 110, 0);
	mlx_put_string(map_sizes->mlx, stars_collected, 185, 0);
	mlx_put_string(map_sizes->mlx, " / ", 192, 0);
	mlx_put_string(map_sizes->mlx, stars_total, 219, 0);
	ft_printf("Stars: %i / %i \n", map_sizes->caught_collectible, \
	map_sizes->collectible_count);
	free(moves);
	free(stars_total);
	free(stars_collected);
}

void	win_check(t_read_map *map_sizes)
{
	if (map_sizes->caught_collectible == map_sizes->collectible_count)
	{
		mlx_image_to_window (map_sizes->mlx, map_sizes->elements.win_img, \
			(((map_sizes->screen_x / 2) * 75) - 112), \
			(((map_sizes->screen_y / 2) * 75) - 112));
		ft_printf("Great job, astronaut! Press esc to finish mission.\n");
		mlx_put_string(map_sizes->mlx, \
		"Great job, astronaut! Press esc to finish mission.\n", 0, 20);
		map_sizes->playable = false;
	}
	else
	{
		ft_printf("Mission isn't completed\n");
		mlx_put_string(map_sizes->mlx, "Mission isn't completed\n", 0, 20);
	}
}

void	black_hole(t_read_map	*map_sizes)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.game_over_img, \
		(((map_sizes->screen_x / 2) * 75) - 112), \
		(((map_sizes->screen_y / 2) * 75) - 112));
	map_sizes->playable = false;
	ft_printf("Game Over. You fell into a black hole. Press esc to exit.\n");
	mlx_put_string (map_sizes->mlx, \
	"Game Over. You fell into a black hole. Press esc to exit.\n", 0, 20);
}
