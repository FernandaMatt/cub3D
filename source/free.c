/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:13:55 by parnaldo          #+#    #+#             */
/*   Updated: 2023/07/17 17:36:36 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	if (game && game->map.mtx)
		free_matrix_chr(game->map.mtx);
}

void	free_texture(t_texture texture)
{
	if (texture.north.ptr && texture.north.img)
		mlx_destroy_image(texture.north.ptr, texture.north.img);
	if (texture.south.ptr && texture.south.img)
		mlx_destroy_image(texture.south.ptr, texture.south.img);
	if (texture.east.ptr && texture.east.img)
		mlx_destroy_image(texture.east.ptr, texture.east.img);
	if (texture.west.ptr && texture.west.img)
		mlx_destroy_image(texture.west.ptr, texture.west.img);
}

int	close_window(t_game *game)
{
	free_texture(game->texture);
	if (game->img.win)
		mlx_destroy_window(game->img.ptr, game->img.win);
	if (game->map.mtx_int)
		free_matrix_int(game->map.mtx_int, game->map.rows);
	if (game->map.mtx)
		free_map(game);
	mlx_destroy_image(game->img.ptr, game->img.img);
	mlx_destroy_display(game->img.ptr);
	free(game->img.ptr);
	exit(0);
}

void	exit_game(char *message, t_game *game)
{
	if (message)
	{
		ft_putendl_fd("Error.", 2);
		ft_putendl_fd(message, 2);
	}
	if (game)
	{
		free_map(game);
		free_texture(game->texture);
		mlx_destroy_display(game->img.ptr);
		free(game->img.ptr);
		exit(0);
	}
}
