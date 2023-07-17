/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/17 17:25:06 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_value(t_game *game, int i, int j)
{
	if (ft_strchr(" 1", game->map.mtx[i][j]))
		game->map.mtx_int[i][j] = 1;
	else if (ft_strchr("0NSEW", game->map.mtx[i][j]))
		game->map.mtx_int[i][j] = 0;
}

int	**malloc_matrix(int height, int width)
{
	int	**mtx;
	int	i;

	i = -1;
	mtx = malloc(sizeof(int *) * height);
	if (!mtx)
		return (NULL);
	while (++i < height)
	{
		mtx[i] = malloc(sizeof(int) * width);
		if (!mtx[i])
			return (NULL);
	}
	return (mtx);
}

void	populate_matrix(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.rows)
			game->map.mtx_int[i][j] = 1;
	}
}

void	transform_map_int(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->map.mtx_int = malloc_matrix(game->map.rows, game->map.cols);
	if (!game->map.mtx_int)
		exit_game("error: malloc failed", game);
	populate_matrix(game);
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->map.mtx[i]))
			put_value(game, i, j);
	}
}
