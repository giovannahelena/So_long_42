/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:22:32 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:19 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	astro_move_right(t_read_map *map_sizes)
{
	if (map_sizes->map_lines[map_sizes->ppos_y][(map_sizes->ppos_x) + 1] != 49)
	{
		map_sizes->elements.astro_img->instances[0].x += 75;
		map_sizes->ppos_x += 1;
		map_sizes->move_count++;
		disp_info(map_sizes);
	}
}

void	astro_move_left(t_read_map *map_sizes)
{
	if (map_sizes->map_lines[map_sizes->ppos_y][(map_sizes->ppos_x) - 1] != 49)
	{
		map_sizes->elements.astro_img->instances[0].x -= 75;
		map_sizes->ppos_x -= 1;
		map_sizes->move_count++;
		disp_info(map_sizes);
	}	
}

void	astro_move_down(t_read_map	*map_sizes)
{
	if (map_sizes->map_lines[(map_sizes->ppos_y) + 1][map_sizes->ppos_x] != 49)
	{
		map_sizes->elements.astro_img->instances[0].y += 75;
		map_sizes->ppos_y += 1;
		map_sizes->move_count++;
		disp_info(map_sizes);
	}
}

void	astro_move_up(t_read_map	*map_sizes)
{
	if (map_sizes->map_lines[(map_sizes->ppos_y) - 1][map_sizes->ppos_x] != 49)
	{
		map_sizes->elements.astro_img->instances[0].y -= 75;
		map_sizes->ppos_y -= 1;
		map_sizes->move_count++;
		disp_info(map_sizes);
	}
}
