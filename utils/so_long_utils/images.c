/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:05:32 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:23 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	textures(t_read_map	*map_sizes)
{
	map_sizes->textures.wall_texture = mlx_load_xpm42 \
	("./textures/Wall.xpm42");
	map_sizes->textures.free_way_texture = mlx_load_xpm42 \
	("./textures/bg.xpm42");
	map_sizes->textures.astro_texture = mlx_load_xpm42 \
	("./textures/Astronaut.xpm42");
	map_sizes->textures.blackhole_texture = mlx_load_xpm42 \
	("./textures/blackhole.xpm42");
	map_sizes->textures.star_texture = mlx_load_xpm42 \
	("./textures/star.xpm42");
	map_sizes->textures.portal_texture = mlx_load_xpm42 \
	("./textures/portal.xpm42");
	map_sizes->textures.win_texture = mlx_load_xpm42 \
	("./textures/win.xpm42");
	map_sizes->textures.frame_texture = mlx_load_xpm42 \
	("./textures/frame.xpm42");
	map_sizes->textures.game_over_texture = mlx_load_xpm42 \
	("./textures/Game_over.xpm42");
}

void	images(t_read_map	*map_sizes)
{
	map_sizes->elements.wall_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.wall_texture->texture);
	map_sizes->elements.free_way_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.free_way_texture->texture);
	map_sizes->elements.astro_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.astro_texture->texture);
	map_sizes->elements.blackhole_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.blackhole_texture->texture);
	map_sizes->elements.star_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.star_texture->texture);
	map_sizes->elements.portal_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.portal_texture->texture);
	map_sizes->elements.game_over_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.game_over_texture->texture);
	map_sizes->elements.win_img = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.win_texture->texture);
	map_sizes->elements.frame_image = mlx_texture_to_image \
	(map_sizes->mlx, &map_sizes->textures.frame_texture->texture);
}

void	d_images(t_read_map	*map_sizes)
{
	mlx_delete_xpm42(map_sizes->textures.astro_texture);
	mlx_delete_xpm42(map_sizes->textures.blackhole_texture);
	mlx_delete_xpm42(map_sizes->textures.frame_texture);
	mlx_delete_xpm42(map_sizes->textures.free_way_texture);
	mlx_delete_xpm42(map_sizes->textures.game_over_texture);
	mlx_delete_xpm42(map_sizes->textures.portal_texture);
	mlx_delete_xpm42(map_sizes->textures.star_texture);
	mlx_delete_xpm42(map_sizes->textures.wall_texture);
	mlx_delete_xpm42(map_sizes->textures.win_texture);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.astro_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.blackhole_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.frame_image);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.free_way_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.game_over_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.portal_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.star_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.wall_img);
	mlx_delete_image(map_sizes->mlx, map_sizes->elements.win_img);
}
