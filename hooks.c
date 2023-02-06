/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:25:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/06 21:39:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	esc_close(mlx_key_data_t keydata, void *param)
{
	t_displ	*s_displ;

	s_displ = (t_displ *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(s_displ->window);
		return ;
	}
}

void	scroll_zoom(double xdelta, double ydelta, void *param)
{
	t_displ	*s_displ;

	s_displ = (t_displ *)param;

	if (ydelta > 0)
		s_displ->s_map->sc = s_displ->s_map->sc * 1.25;
	if (ydelta < 0)
	{
		s_displ->s_map->sc = s_displ->s_map->sc / 1.25;
		if (s_displ->s_map->sc < 1)
			s_displ->s_map->sc = 1;
	}
	memset(s_displ->img->pixels, 0, s_displ->img->width * s_displ->img->height * sizeof(int32_t));
	ft_draw_x(&(s_displ->s_map), &s_displ);
	ft_draw_y(&(s_displ->s_map), &s_displ);
}