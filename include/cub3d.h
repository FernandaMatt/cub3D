/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:16:05 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/17 17:24:27 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include "constants.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h> //open().
# include <stdio.h> //printf
# include <math.h>

void			setup(t_game *game);
void			render_game(t_game *game);
void			exit_game(char *message, t_game *game);
int				close_window(t_game *game);

// interpretate_map
void			interpretate_map(t_game *game, char *path_name);
int				has_all_information(t_game *game);
int				open_file(char *file_path, t_game *game);

//Texture
int				is_xpm(char *line);
int				get_texture(t_game *game, char *line);
int				is_north(char *cardinal, t_game *game);
int				is_south(char *cardinal, t_game *game);
int				is_west(char *cardinal, t_game *game);
int				is_east(char *cardinal, t_game *game);

// Color
int				is_color(char *line);
void			get_color(t_game *game, char *line);
int				is_ceiling(char *cardinal, t_game *game);
int				is_floor(char *cardinal, t_game *game);

// Common libft
void			update_matrix(char ***matrix, char *new_line);
int				ft_count_words(char const *s, char c);

// Validate_map
void			validate_map(t_game *game);
void			validate_player(t_game *game);
void			validate_char(t_game *game);
void			validate_border(t_game *game);
int				validate_up(t_game *game);
int				validate_down(t_game *game);
int				validate_left(t_game *game);
int				validate_right(t_game *game);
void			validate_middle(t_game *game);
int				is_valid_up_down(char *line_updown, int pos);
int				check_map_extension(char *file_path);

// Transform_map
void			transform_map_int(t_game *game);
void			transpose_matrix(t_game *game);
void			free_matrix_int(int **mtx, int n_rows);
int				**malloc_matrix(int height, int width);

// Ray casting
void			render_map3d(t_game *game);
void			raycast(t_game *game);

// Movement
void			walk_backward(t_game *game);
void			turn_right(t_player *player);
void			walk_forward(t_game *game);
void			turn_left(t_player *player);
void			walk_right(t_game *game);
void			walk_left(t_game *game);

// Draw
void			draw_square(t_img *img, int x0, int y0, int color);
void			draw_background(t_game game);
void			pixel_put(t_img *data, int x, int y, int color);
void			bresenham_x(t_img *img, int i[2], int f[2], int color);
void			bresenham_y(t_img *img, int i[2], int f[2], int color);
void			draw_x_l(t_game *game, t_ray_info *ray, int l_height, int x);
void			draw_background(t_game game);

// Calculations
t_double_vector	calc_ray_dir(int x, t_game *game);
void			calc_ray_info(t_game *game, t_ray_info *ray);
void			calc_wall_hit(t_game *game, t_ray_info *ray);
void			calc_perp_wall_dist(t_game *game, t_ray_info *ray);
int				calc_lowest_pixel(int l_height);
int				calc_highest_pixel(int l_height);
double			calc_tile_hit_x(t_game *game, t_ray_info *ray);
int				calc_tex_hit_x(t_game *game, t_ray_info *ray, t_img tex);
unsigned long	tex_color(t_img tex, int tex_pos, int tex_hit_x);
t_img			def_tex(t_game *game, t_ray_info *ray);

// Utils
void			print_mtx(t_game *game);
void			free_texture(t_texture texture);
int				check_color(char *str1, int nbr);

#endif
