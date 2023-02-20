/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:58:02 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/20 19:28:45 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*places pixels to draw a line, 
following Bresenhams algorithm*/

void	draw_line_low(mlx_image_t *img, t_2d_px s_p1, t_2d_px s_p2)
{
	int	dx;
	int	dy;
	int	p;
	int	y_step;
	int	color;
	double position;
	int start;
		
	// color = s_p1.pt_rgba;
	start = s_p1.x;
	y_step = 1;
	dx = s_p2.x - s_p1.x;
	dy = s_p2.y - s_p1.y;
	if (dy < 0)
	{
		y_step = -1;
		// color = s_p2.pt_rgba;
	}
	p = 2 * dy * y_step - dx;
	while (s_p1.x < s_p2.x)
	{	
		position = position_pct(s_p2.x, start, s_p1.x);
		color = get_rgba(position, s_p1.pt_rgba, s_p2.pt_rgba);
		s_p1.pt_rgba = color;
		if (s_p1.x < WIDTH && s_p1.y < HEIGHT && s_p1.x > 0 && s_p1.y > 0)
			mlx_put_pixel(img, s_p1.x++, s_p1.y, color);
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

void	draw_line_high(mlx_image_t *img, t_2d_px s_p1, t_2d_px s_p2)
{
	int	dx;
	int	dy;
	int	p;
	int	x_step;
	int	color;
	double position;
	int start;

	// color = s_p1.pt_rgba;
	start = s_p1.y;
	x_step = 1;
	dx = s_p2.x - s_p1.x;
	dy = s_p2.y - s_p1.y;
	if (dx < 0)
	{
		// color = s_p2.pt_rgba;
		x_step = -1;
	}
	p = 2 * dx * x_step - dy;
	while (s_p1.y < s_p2.y)
	{
		position = position_pct(s_p2.y, start, s_p1.y);
		color = get_rgba(position, s_p1.pt_rgba, s_p2.pt_rgba);
		s_p1.pt_rgba = color;
		if (s_p1.x < WIDTH && s_p1.y < HEIGHT && s_p1.x > 0 && s_p1.y > 0)
			mlx_put_pixel(img, s_p1.x, s_p1.y++, color);
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

void	draw_line(mlx_image_t *img, t_2d_px s_p1, t_2d_px s_p2)
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