/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:25:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/19 19:59:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	single_key_h(mlx_key_data_t keydata, t_map *s_map)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(s_map->window);
		return ;
	}
	if (keydata.key == MLX_KEY_1)
	{
		ft_defaults(s_map);
		draw_all(&ft_isometric, s_map);
	}
	if (keydata.key == MLX_KEY_2)
	{
		ft_defaults(s_map);
		draw_all(&ft_parallel_x, s_map);
	}
	if (keydata.key == MLX_KEY_3)
	{
		ft_defaults(s_map);
		draw_all(&ft_parallel_y, s_map);
	}
	if (keydata.key == MLX_KEY_4)
	{
		ft_defaults(s_map);
		draw_all(&ft_parallel_z, s_map);
	}
}

static void	rotations_hook(keys_t key, t_map *s_map)
{
	if ((key == MLX_KEY_W))
		s_map->s_rot.x_angle += M_PI / 180;
	if (key == MLX_KEY_Q)
		s_map->s_rot.x_angle -= M_PI / 180;
	if (key == MLX_KEY_A)
		s_map->s_rot.y_angle += M_PI / 180;
	if (key == MLX_KEY_S)
		s_map->s_rot.y_angle -= M_PI / 180;
	if (key == MLX_KEY_Z)
		s_map->s_rot.z_angle += M_PI / 180;
	if (key == MLX_KEY_X)
		s_map->s_rot.z_angle -= M_PI / 180;
	if (s_map->s_rot.x_angle >= 2 * M_PI || \
	s_map->s_rot.x_angle <= -2 * M_PI)
		s_map->s_rot.x_angle = 0;
	if (s_map->s_rot.y_angle >= 2 * M_PI || \
	s_map->s_rot.y_angle <= -2 * M_PI)
		s_map->s_rot.y_angle = 0;
	if (s_map->s_rot.z_angle >= 2 * M_PI || \
	s_map->s_rot.z_angle <= -2 * M_PI)
		s_map->s_rot.z_angle = 0;
	draw_all(&ft_iso_rot, s_map);
}

static void	zoom_hook(keys_t key, t_map *s_map)
{
	if ((key == MLX_KEY_UP))
		s_map->center.y_0 -= 5;
	if (key == MLX_KEY_DOWN)
		s_map->center.y_0 += 5;
	if (key == MLX_KEY_LEFT)
		s_map->center.x_0 -= 5;
	if (key == MLX_KEY_RIGHT)
		s_map->center.x_0 += 5;
	draw_all(&ft_isometric, s_map);
}

void	genhook_re(t_map *s_map)
{
	if (mlx_is_key_down(s_map->window, MLX_KEY_UP))
		zoom_hook(MLX_KEY_UP, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_DOWN))
		zoom_hook(MLX_KEY_DOWN, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_LEFT))
		zoom_hook(MLX_KEY_LEFT, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_RIGHT))
		zoom_hook(MLX_KEY_RIGHT, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_W))
		rotations_hook(MLX_KEY_W, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_Q))
		rotations_hook(MLX_KEY_Q, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_A))
		rotations_hook(MLX_KEY_A, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_S))
		rotations_hook(MLX_KEY_S, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_Z))
		rotations_hook(MLX_KEY_Z, s_map);
	if (mlx_is_key_down(s_map->window, MLX_KEY_X))
		rotations_hook(MLX_KEY_X, s_map);
	return ;
}

void	scroll_scale(double xdelta, double ydelta, t_map *s_map)
{
	if (ydelta > 0 && mlx_is_key_down(s_map->window, MLX_KEY_Z))
		s_map->z_sc += 0.1;
	else if (ydelta > 0)
		s_map->sc = s_map->sc * 1.15;
	if (ydelta < 0 && mlx_is_key_down(s_map->window, MLX_KEY_Z))
		s_map->z_sc -= 0.1;
	else if (ydelta < 0)
	{
		s_map->sc = s_map->sc / 1.15;
		if (s_map->sc < 1)
			s_map->sc = 1;
	}
	draw_all(&ft_isometric, s_map);
}