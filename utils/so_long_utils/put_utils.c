/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:42 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:09 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	put_astro(t_read_map	*map_sizes)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.astro_img, \
	(map_sizes->ppos_x * 75), (map_sizes->ppos_y * 75));
}

void	put_wall(t_read_map *map_sizes, int x, int y)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.wall_img, \
	(x * 75), (y * 75));
}

void	put_free_way(t_read_map *map_sizes, int x, int y)
{
	mlx_image_to_window(map_sizes->mlx, map_sizes->elements.free_way_img, \
	(x * 75), (y * 75));
}
