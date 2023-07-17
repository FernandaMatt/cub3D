/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:38 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/17 09:26:46 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_double_vector	calc_ray_dir(int x, t_game *game)
{
	double			camera_x;
	t_double_vector	ray_dir;

	camera_x = 2.0 * x / (double)LENGHT - 1.0;
	ray_dir.x = game->player.dir_x + game->player.cam_plane_dir_x * camera_x;
	ray_dir.y = game->player.dir_y + game->player.cam_plane_dir_y * camera_x;
	return (ray_dir);
}

void	calc_ray_info(t_game *game, t_ray_info *ray)
{
	ray->map_hit.x = trunc(game->player.x);
	ray->map_hit.y = trunc(game->player.y);
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (game->player.x - ray->map_hit.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_hit.x + 1.0 - game->player.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (game->player.y - ray->map_hit.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_hit.y + 1.0 - game->player.y) * ray->delta.y;
	}
}

void	calc_wall_hit(t_game *game, t_ray_info *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map_hit.x += ray->step.x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map_hit.y += ray->step.y;
			ray->side_hit = 1;
		}
		if (game->map.mtx_int[ray->map_hit.x][ray->map_hit.y] > 0)
			hit = 1;
	}
}

void	calc_perp_wall_dist(t_game *game, t_ray_info *ray)
{
	calc_ray_info(game, ray);
	calc_wall_hit(game, ray);
	if (ray->side_hit == 0)
		ray->perp_wall_dist = (ray->side.x - ray->delta.x);
	else
		ray->perp_wall_dist = (ray->side.y - ray->delta.y);
}

int	calc_lowest_pixel(int l_height)
{
	int	draw_start;

	draw_start = -l_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}
