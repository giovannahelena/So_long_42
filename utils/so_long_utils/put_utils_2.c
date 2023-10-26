/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:40:48 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:12 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	put_collectible(t_read_map	*map_sizes, int x, int y)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.free_way_img, \
	(x * 75), (y * 75));
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.star_img, \
	(x * 75), (y * 75));
	map_sizes->colectibles_positions[map_sizes->i][0] = x;
	map_sizes->colectibles_positions[map_sizes->i][1] = y;
	map_sizes->i++;
}

void	put_blackhole(t_read_map	*map_sizes, int x, int y)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.free_way_img, \
	(x * 75), (y * 75));
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.blackhole_img, \
	(x * 75), (y * 75));
}

void	put_exit(t_read_map	*map_sizes, int x, int y)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.free_way_img, \
	(x * 75), (y * 75));
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.portal_img, \
	(x * 75), (y * 75));
}
