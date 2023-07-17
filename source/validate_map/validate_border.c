/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/17 17:46:52 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	validate_border(t_game *game)
{
	if (!validate_up(game)
		|| !validate_down(game)
		|| !validate_left(game)
		|| !validate_right(game))
	{
		printf("It's just another brick in the wall...\n");
		exit_game("Map needs to be surrounded by walls.", game);
	}
}
