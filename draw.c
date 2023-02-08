/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:43 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/08 19:38:34 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*places pixels to draw a line, 
following Bresenhams algorithm*/
void	draw_line_low(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2)
{
	int	dx;
	int	dy;
	int	p;
	int	y_step;

	y_step = 1;
	dx = s_p2.x - s_p1.x;
	dy = s_p2.y - s_p1.y;
	if (dy < 0)
		y_step = -1;
	p = 2 * dy * y_step - dx;
	while (s_p1.x < s_p2.x)
	{
		if (s_p1.x < WIDTH && s_p1.y < HEIGHT && s_p1.x > 0 && s_p1.y > 0)
			mlx_put_pixel(img, s_p1.x++, s_p1.y, 0xEE4B2BFF);
		else
			s_p1.x++;
		if (p < 0)
			p = p + 2 * dy * y_step;
		else
		{
			p = p + 2 * dy * y_step - 2 * dx;
			s_p1.y = s_p1.y + y_step;
		}
	}
}

void	draw_line_high(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2)
{
	int	dx;
	int	dy;
	int	p;
	int	x_step;

	x_step = 1;
	dx = s_p2.x - s_p1.x;
	dy = s_p2.y - s_p1.y;
	if (dx < 0)
		x_step = -1;
	p = 2 * dx * x_step - dy;
	while (s_p1.y < s_p2.y)
	{
		if (s_p1.x < WIDTH && s_p1.y < HEIGHT && s_p1.x > 0 && s_p1.y > 0)
			mlx_put_pixel(img, s_p1.x, s_p1.y++, 0xEE4B2BFF);
		else
			s_p1.y++;
		if (p < 0)
			p = p + 2 * dx * x_step;
		else
		{
			p = p + 2 * dx * x_step - 2 * dy;
			s_p1.x = s_p1.x + x_step;
		}
	}
}

void	draw_line(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2)
{
	if (abs(s_p2.y - s_p1.y) < abs(s_p2.x - s_p1.x))
	{
		if (s_p1.x > s_p2.x)
			draw_line_low(img, s_p2, s_p1);
		else
			draw_line_low(img, s_p1, s_p2);
	}
	else
	{
		if (s_p1.y > s_p2.y)
			draw_line_high(img, s_p2, s_p1);
		else
			draw_line_high(img, s_p1, s_p2);
	}
}

void	ft_draw_x(mlx_image_t *img, t_map *s_map)
{
	int			column;
	int			row;
	t_2d_isom	p_1;
	t_2d_isom	p_2;

	row = -1;
	while (++row < s_map->y_max)
	{
		column = 0;
		p_1 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
		while (++column < s_map->x_max)
		{
			p_2 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
			// printf("Isometric x p1:[%d, %d]\n", p_1.x, p_1.y);
			// printf("Isometric x p2:[%d, %d]\n", p_2.x, p_2.y);
			draw_line(img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

void	ft_draw_y(mlx_image_t *img, t_map *s_map)
{
	int			column;
	int			row;
	t_2d_isom	p_1;
	t_2d_isom	p_2;

	column = -1;
	while (++column < s_map->x_max)
	{
		row = 0;
		p_1 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
		while (++row < s_map->y_max)
		{
			p_2 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
			// printf("Isometric y p1:[%d, %d]\n", p_1.x, p_1.y);
			// printf("Isometric y p2:[%d, %d]\n", p_2.x, p_2.y);
			draw_line(img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

// void	ft_draw_all(mlx_image_t *img, t_map *s_map)
// {
// 	int			column;
// 	int			row;
// 	t_2d_isom	p_1;
// 	t_2d_isom	p_2;

// 	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
// 	row = -1;
// 	while (++row < s_map->y_max)
// 	{
// 		column = 0;
// 		p_1 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
// 		while (++column < s_map->x_max)
// 		{
// 			p_2 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
// 			draw_line(img, p_1, p_2);
// 			p_1 = p_2;
// 		}
// 	}
// 	column = -1;
// 	while (++column < s_map->x_max)
// 	{
// 		row = 0;
// 		p_1 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
// 		while (++row < s_map->y_max)
// 		{
// 			p_2 = ft_2d_convert(&s_map->mtrx[row][column], s_map);
// 			draw_line(img, p_1, p_2);
// 			p_1 = p_2;
// 		}
// 	}
// }

void	draw_all(mlx_image_t *img, t_map *s_map)
{
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	ft_draw_x(img, s_map);
	ft_draw_y(img, s_map);
	return ;
}