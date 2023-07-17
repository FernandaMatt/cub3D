/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/17 17:52:21 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!check_map_extension(argv[1]))
			ft_putendl_fd("Error.\nMap file extension. `.cub´ expected.", 1);
		else
		{
			setup(&game);
			interpretate_map(&game, argv[1]);
			if (!has_all_information(&game))
				exit_game("Incomplete data in the .cub file.", &game);
			validate_map(&game);
			transform_map_int(&game);
			render_game(&game);
			exit_game(NULL, &game);
		}
	}
	else
		ft_putendl_fd("Usage: ./cub3D <map.cub>", 1);
	return (1);
}
