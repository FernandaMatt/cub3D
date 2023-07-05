/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 19:21:14 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_ceiling(char *cardinal, t_game *game)
{
	if (!ft_strncmp("C", cardinal, 2) && game->texture.ceiling == -1)
		return (1);
	return (0);
}

int	is_floor(char *cardinal, t_game *game)
{
	if (!ft_strncmp("F", cardinal, 2) && game->texture.floor == -1)
		return (1);
	return (0);
}

int	is_color(char *line)
{
	if (ft_count_words(line, ',') != 3)
		return (0);
	return (1);
}

int	check_color(char *str1, int nbr)
{
	char	*color_str;

	color_str = ft_itoa(nbr);
	if (ft_strncmp(str1, color_str, ft_strlen(str1)))
	{
		free(color_str);
		return (0);
	}
	free(color_str);
	return (1);
}
