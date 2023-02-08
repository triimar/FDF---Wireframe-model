/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:25:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/08 21:39:05 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	esc_close(mlx_key_data_t keydata, t_map *s_map)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(s_map->window);
		return ;
	}
	// if (keydata.key == MLX_KEY_UP)
	// {
	// 	s_map->center.y_0 -= 5;
	// 	draw_all(s_map->img, s_map);
	// }
	// if (keydata.key == MLX_KEY_DOWN)
	// {
	// 	s_map->center.y_0 += 5;
	// 	draw_all(s_map->img, s_map);
	// }
	// if (keydata.key == MLX_KEY_LEFT)
	// {
	// 	s_map->center.x_0 -= 5;
	// 	draw_all(s_map->img, s_map);
	// }
	// if (keydata.key == MLX_KEY_RIGHT)
	// {
	// 	s_map->center.x_0 += 5;
	// 	draw_all(s_map->img, s_map);
	// }
	return ;
}

void	genhook_re(t_map *s_map)
{
	if (mlx_is_key_down(s_map->window, MLX_KEY_UP))
	{
		s_map->center.y_0 -= 5;
		draw_all(s_map->img, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_DOWN))
	{
		s_map->center.y_0 += 5;
		draw_all(s_map->img, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_LEFT))
	{
		s_map->center.x_0 -= 5;
		draw_all(s_map->img, s_map);
	}
	if (mlx_is_key_down(s_map->window, MLX_KEY_RIGHT))
	{
		s_map->center.x_0 += 5;
		draw_all(s_map->img, s_map);
	}
	return ;
}

void	scroll_zoom(double xdelta, double ydelta, t_map *s_map)
{
	if (ydelta > 0)
	{
		s_map->sc = s_map->sc * 1.15;
	}
	if (ydelta < 0)
	{
		s_map->sc = s_map->sc / 1.15;
		if (s_map->sc < 1)
			s_map->sc = 1;
	}
	draw_all(s_map->img, s_map);
}