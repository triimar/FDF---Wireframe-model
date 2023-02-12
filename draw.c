/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:43 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/12 22:58:34 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_x(t_2d_px (*f)(t_3d *, t_map *), t_map *s_map)
{
	int		column;
	int		row;
	t_2d_px	p_1;
	t_2d_px	p_2;

	row = -1;
	while (++row < s_map->y_max)
	{
		column = 0;
		p_1 = f(&s_map->mtrx[row][column], s_map);
		while (++column < s_map->x_max)
		{
			p_2 = f(&s_map->mtrx[row][column], s_map);
			draw_line(s_map->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

static void	ft_draw_y(t_2d_px (*f)(t_3d *, t_map *), t_map *s_map)
{
	int			column;
	int			row;
	t_2d_px		p_1;
	t_2d_px		p_2;

	column = -1;
	while (++column < s_map->x_max)
	{
		row = 0;
		p_1 = f(&s_map->mtrx[row][column], s_map);
		while (++row < s_map->y_max)
		{
			p_2 = f(&s_map->mtrx[row][column], s_map);
			draw_line(s_map->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

void	draw_all(t_conv_f funct, t_map *s_map)
{
	ft_memset(s_map->img->pixels, 0, s_map->img->width * \
	s_map->img->height * sizeof(int32_t));
	ft_draw_x(funct, s_map);
	ft_draw_y(funct, s_map);
	return ;
}
