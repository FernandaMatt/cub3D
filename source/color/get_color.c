/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 11:51:48 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_number(char **mtx, int r, int g, int b)
{
	char *rgb;

	if (mtx[0][0] == '-'
		|| mtx[1][0] == '-'
		|| mtx [2][0] == '-')
		return (0);
	rgb = ft_itoa(r);
	if (ft_strncmp(mtx[0], rgb, ft_strlen(mtx[0])))
	{
		free(rgb);
		return (0);
	}
	free(rgb);
	rgb = ft_itoa(g);
	if (ft_strncmp(mtx[1], rgb, ft_strlen(mtx[1])))
	{
		free(rgb);
		return (0);
	}
	free(rgb);
	rgb = ft_itoa(b);
	if (ft_strncmp(mtx[2], rgb, ft_strlen(mtx[2])))
	{
		free(rgb);
		return (0);
	}
	free(rgb);
	return (1);
}

void	invalid_rgb(char **mtx, t_game *game)
{
	free_matrix_chr(mtx);
	exit_game("Number rgb not valid", game);
}

int	ft_count_line(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		i++;
	return (i);
}

int	translate_rgb(char *rgb, t_game *game)
{
	int		r;
	int		g;
	int		b;
	int		c;
	char	**lonely;

	if (ft_count_words(rgb, ',') != 3)
		exit_game("Number rgb not valid", game);
	lonely = ft_split(rgb, ',');
	r = ft_atoi(lonely[0]);
	g = ft_atoi(lonely[1]);
	b = ft_atoi(lonely[2]);
	if (!is_valid_number(lonely, r, g, b))
		invalid_rgb(lonely, game);
	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	free_matrix_chr(lonely);
	return (c);
}

void	get_color(t_game *game, char *line)
{
	char	*cardinal;
	char	**line_mtx;
	char	*arg;

	line_mtx = ft_split(line, ' ');
	cardinal = line_mtx[0];
	arg = line_mtx[1];
	if (is_ceiling(cardinal, game))
		game->texture.ceiling = translate_rgb(arg, game);
	else if (is_floor(cardinal, game))
		game->texture.floor = translate_rgb(arg, game);
	free_matrix_chr(line_mtx);
}
