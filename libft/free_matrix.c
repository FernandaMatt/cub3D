/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:37:46 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/03 12:12:22 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_matrix_int(int **mtx, int n_rows)
{
	int	i;

	if (mtx)
	{
		i = -1;
		while (++i < n_rows)
			free(mtx[i]);
		free(mtx);
	}
}

void	free_matrix_chr(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = -1;
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
}
