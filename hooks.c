/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:25:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/13 21:17:27 by tmarts           ###   ########.fr       */
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

void	genhook_re(t_map *s_map)
{
	if (mlx_is_key_down(s_map->window, MLX_KEY_UP))
	{
		s_map->center.y_0 -= 5;
		draw_all(&ft_isometric, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_DOWN))
	{
		s_map->center.y_0 += 5;
		draw_all(&ft_isometric, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_LEFT))
	{
		s_map->center.x_0 -= 5;
		draw_all(&ft_isometric, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_RIGHT))
	{
		s_map->center.x_0 += 5;
		draw_all(&ft_isometric, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_W))
	{
		s_map->s_rot.x_angle += 1 * M_PI / 180;
		rot_draw(&ft_isometric, s_map);
	}
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