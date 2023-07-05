/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:37:54 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/05 19:15:15 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65362 || keycode == 119)
		game->key.w_is_press = 1;
	if (keycode == 97)
		game->key.a_is_press = 1;
	if (keycode == 65364 || keycode == 115)
		game->key.s_is_press = 1;
	if (keycode == 100)
		game->key.d_is_press = 1;
	if (keycode == 65363)
		game->key.ra_is_press = 1;
	if (keycode == 65361)
		game->key.la_is_press = 1;
	if (keycode == 97)
		game->key.a_is_press = 1;
	if (keycode == 100)
		game->key.d_is_press = 1;
	if (keycode == 109)
	{
		if (game->key.m_is_press)
			game->key.m_is_press = 0;
		else
			game->key.m_is_press = 1;
	}	
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 65362 || keycode == 119)
		game->key.w_is_press = 0;
	if (keycode == 97)
		game->key.a_is_press = 0;
	if (keycode == 65364 || keycode == 115)
		game->key.s_is_press = 0;
	if (keycode == 100)
		game->key.d_is_press = 0;
	if (keycode == 65363)
		game->key.ra_is_press = 0;
	if (keycode == 65361)
		game->key.la_is_press = 0;
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->key.w_is_press + game->key.s_is_press + game->key.d_is_press
		+ game->key.ra_is_press + game->key.la_is_press + game->key.a_is_press)
	{
		if (game->key.w_is_press)
			walk_forward (game);
		if (game->key.a_is_press)
			walk_left (game);
		if (game->key.s_is_press)
			walk_backward (game);
		if (game->key.d_is_press)
			walk_right (game);
		if (game->key.ra_is_press)
			turn_right (&game->player);
		if (game->key.la_is_press)
			turn_left (&game->player);
	}
	render_map3d(game);
	if (game->key.m_is_press)
	{
		render_map2d(game, SIZE_MMAP);
		render_player(&game->img, game->player, 9);
	}
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	return (0);
}

void	create_window_mlx(t_game *game)
{
	game->img.win = mlx_new_window(game->img.ptr, LENGHT, HEIGHT, "cub3D");
	if (game->img.win == NULL)
		exit_game("error: mlx window failed", game);
	game->img.img = mlx_new_image(game->img.ptr, LENGHT, HEIGHT);
	if (game->img.img == NULL)
		exit_game("error: mlx image failed", game);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	if (game->img.addr == NULL)
		exit_game("error: mlx address failed", game);
}

void	render_game(t_game *game)
{
	create_window_mlx(game);
	transpose_matrix(game);
	render_map3d(game);
	mlx_hook(game->img.win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->img.win, 3, 1L << 1, handle_key_release, game);
	mlx_hook(game->img.win, 17, 0, close_window, game);
	mlx_loop_hook(game->img.ptr, loop_hook, game);
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	mlx_loop(game->img.ptr);
}
