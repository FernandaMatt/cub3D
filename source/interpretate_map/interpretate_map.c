/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/17 10:48:39 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_max_col(t_game *game, char *line)
{
	int	len_line;

	len_line = ft_strlen(line);
	if (len_line > game->map.cols)
		game->map.cols = len_line;
}

/*
** Cut the new line at the end of the line
** Decide if the line is a texture or a color or a map.
** Call the right function to interpretate the line.
*/
int	interpretate_line(t_game *game, char *line_pre)
{
	char	*line2;
	char	*line;

	line2 = ft_strtrim(line_pre, "\n");
	line = ft_strtrim(line2, " ");
	free(line2);
	if (is_xpm(line))
	{
		if (!get_texture(game, line))
		{
			free(line);
			return (0);
		}
	}
	else if (is_color(line))
		get_color(game, line);
	else
	{
		update_matrix(&game->map.mtx, line);
		game->map.rows++;
		get_max_col(game, line);
	}
	free(line);
	return (1);
}

/*
** Open the file to read.
** Read the file line by line.
** If the line is not empty, interpretate it.
** At end, check if all information needed was given.
*/
void	interpretate_map(t_game *game, char *file_path)
{
	char	*line;
	int		fd;
	int		status;

	status = 1;
	fd = open_file(file_path);
	line = get_nl(fd);
	while (line)
	{
		if (!is_empty_line(line))
			status = interpretate_line(game, line);
		else if (game->map.mtx || !status)
		{
			free(line);
			close(fd);
			exit_game("Empty line or false info. Invalid map entry.", game);
		}
		free(line);
		line = get_nl(fd);
	}
	close(fd);
}
