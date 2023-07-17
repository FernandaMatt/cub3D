/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/17 17:47:40 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_cell(char map_cell)
{
	if (ft_strchr("NSEW 01", map_cell) != 0)
		return (1);
	return (0);
}

void	validate_char(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.mtx[++i])
	{
		j = -1;
		while (game->map.mtx[i][++j])
		{
			if (!is_valid_cell(game->map.mtx[i][j]))
				exit_game("Invalid char in map.", game);
		}
	}
}
