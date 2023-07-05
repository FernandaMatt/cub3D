/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 19:11:06 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	update_matrix(char ***matrix, char *new_line)
{
	char	**new_matrix;
	int		i;

	i = 0;
	if (!*matrix)
	{
		*matrix = malloc(sizeof(char *) * 2);
		(*matrix)[0] = ft_strdup(new_line);
		(*matrix)[1] = NULL;
	}
	else
	{
		while ((*matrix)[i])
			i++;
		new_matrix = malloc(sizeof(char *) * (i + 2));
		i = -1;
		while ((*matrix)[++i])
			new_matrix[i] = ft_strdup((*matrix)[i]);
		new_matrix[i] = ft_strdup(new_line);
		new_matrix[i + 1] = NULL;
		free_matrix_chr(*matrix);
		*matrix = new_matrix;
	}
}

int	ft_count_words(char const *s, char sep)
{
	char	**mtx;
	int		count;

	count = 0;
	mtx = ft_split(s, sep);
	while (mtx[count])
		count++;
	free_matrix_chr(mtx);
	return (count);
}

int	**malloc_ma(int height, int width)
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	transpose_matrix(t_game *game)
{
	int	**mtx;
	int	i;
	int	j;

	mtx = malloc_matrix(game->map.cols, game->map.rows);
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			mtx[j][i] = game->map.mtx_int[i][j];
		}
	}
	free_matrix_int(game->map.mtx_int, game->map.rows);
	game->map.mtx_int = mtx;
	ft_swap(&game->map.rows, &game->map.cols);
}
