/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/17 17:46:21 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_img	get_argure(char *path, t_game *game)
{
	t_img	texture;

	texture.ptr = game->img.ptr;
	texture.img = mlx_xpm_file_to_image(texture.ptr,
			path,
			&texture.width,
			&texture.height);
	if (!texture.img)
		return (texture);
	texture.addr = mlx_get_data_addr(texture.img,
			&texture.bpp,
			&texture.line_len,
			&texture.endian);
	return (texture);
}

int	load_texture(char *arg, char *cardinal, t_game *game)
{
	if (is_north(cardinal, game))
	{
		game->texture.north = get_argure(arg, game);
		if (!game->texture.north.img)
			return (0);
	}
	else if (is_south(cardinal, game))
	{
		game->texture.south = get_argure(arg, game);
		if (!game->texture.south.img)
			return (0);
	}
	else if (is_west(cardinal, game))
	{
		game->texture.west = get_argure(arg, game);
		if (!game->texture.west.img)
			return (0);
	}
	else if (is_east(cardinal, game))
	{
		game->texture.east = get_argure(arg, game);
		if (!game->texture.east.img)
			return (0);
	}
	return (1);
}

int	get_texture(t_game *game, char *line)
{
	char	*cardinal;
	char	**line_mtx;
	char	*arg;

	if (ft_count_words(line, ' ') != 2)
		exit_game("Incorrect number of information in .cub file.", game);
	line_mtx = ft_split(line, ' ');
	cardinal = line_mtx[0];
	arg = line_mtx[1];
	if (!load_texture(arg, cardinal, game))
	{
		free_matrix_chr(line_mtx);
		return (0);
	}
	free_matrix_chr(line_mtx);
	return (1);
}

int	is_xpm(char *line)
{
	while (*line && *line != '.')
		line++;
	if (!ft_strncmp(line, ".xpm", 4) && *(line + 4) == '\0')
		return (1);
	return (0);
}
