/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/06 14:35:32 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_mtx(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			printf("%d", game->map.mtx_int[i][j]);
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!check_map_extension(argv[1]))
			ft_putendl_fd("Error: map file extension. `.cub´ expected", 1);
		else
		{
			setup(&game);
			interpretate_map(&game, argv[1]);
			if (!has_all_information(&game))
				exit_game("Missing information", &game);
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
