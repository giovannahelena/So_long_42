/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:32:01 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:27:41 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	xpm_t	*wall_texture;
	xpm_t	*free_way_texture;
	xpm_t	*astro_texture;
	xpm_t	*blackhole_texture;
	xpm_t	*star_texture;
	xpm_t	*portal_texture;
	xpm_t	*win_texture;
	xpm_t	*frame_texture;
	xpm_t	*game_over_texture;
}							t_textures;

typedef struct s_elements
{
	mlx_image_t		*wall_img;
	mlx_image_t		*free_way_img;
	mlx_image_t		*astro_img;
	mlx_image_t		*blackhole_img;
	mlx_image_t		*star_img;
	mlx_image_t		*portal_img;
	mlx_image_t		*game_over_img;
	mlx_image_t		*win_img;
	mlx_image_t		*frame_image;
}								t_elements;

typedef struct s_read_map
{
	int			screen_x;
	int			screen_y;
	int			ppos_x;
	int			ppos_y;
	int			epos_x;
	int			epos_y;
	int			collectible_count;
	int			caught_collectible;
	int			move_count;
	t_elements	elements;
	t_textures	textures;
	char		**map_lines;
	char		**map_copy;
	mlx_t		*mlx;
	int			**colectibles_positions;
	bool		playable;
	int			x;
	int			y;
	int			i;
}							t_read_map;

void			get_map(int map, t_read_map *map_sizes);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t	nmemb, size_t	size);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			**ft_split(char const *s, char c);
int				ft_printf(const char *p1, ...);
int				count_y(const char *s, char c);
t_read_map		*check_map(t_read_map	*map_sizes);
void			create_screen(t_read_map	*map_sizes);
void			play_game(mlx_key_data_t keydata, void *map_sizes);
void			element_check(void *map);
void			disp_info(t_read_map *map_sizes);
void			astro_move_right(t_read_map *map_sizes);
void			astro_move_left(t_read_map *map_sizes);
void			astro_move_down(t_read_map *map_sizes);
void			astro_move_up(t_read_map *map_sizes);
void			win_check(t_read_map *map_sizes);
void			catch_star(t_read_map *map_sizes);
void			black_hole(t_read_map	*map_sizes);
void			textures(t_read_map	*map_sizes);
void			images(t_read_map	*map_sizes);
void			d_images(t_read_map	*map_sizes);
void			put_wall(t_read_map *map_sizes, int x, int y);
void			put_free_way(t_read_map *map_sizes, int x, int y);
void			put_collectible(t_read_map	*map_sizes, int x, int y);
void			put_blackhole(t_read_map	*map_sizes, int x, int y);
void			put_exit(t_read_map	*map_sizes, int x, int y);
void			put_astro(t_read_map	*map_sizes);
void			alloc_collectibles(t_read_map *map_sizes);
void			disalloc_collectibles(t_read_map *map_sizes);
void			check_dimensions(t_read_map	*map_sizes);
void			check_elements(t_read_map	*map_sizes);
void			check_finals(t_read_map	*map_sizes);
void			finish(t_read_map	*map_sizes);
void			quit(t_read_map *map_sizes);
void			disalloc_collectibles(t_read_map *map_sizes);
int				check_paths(t_read_map *map_sizes);
char			**flood_fill(char **map, int y, int x);

#endif
