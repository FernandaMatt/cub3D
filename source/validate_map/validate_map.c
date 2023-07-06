/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/06 14:34:27 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	validate_map(t_game *game)
{
	validate_char(game);
	validate_player(game);
	validate_border(game);
	validate_middle(game);
}

int	check_map_extension(char* file_path)
{
	if (file_path && ft_strnstr(file_path, ".cub", ft_strlen(file_path)))
		return (1);
	return (0);
}