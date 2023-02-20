/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:39:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/20 18:18:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	position_pct(double max, double min, double current)
{
	double	position;
	double	range;

	range = max - min;
	position = current - min;
	return (position / range);
}

int	chl_val(int st_rgba, int end_rgba, double position_pct)
{
	int	current;

	current = (int)((1 - position_pct) * st_rgba + position_pct * end_rgba);
	return (current);
}

// int	get_rgba(double max, double min, double current, t_2d_px s_2d_px)
int	get_rgba(double pct, int start, int end)
{
	int		red;
	int		green;
	int		blue;

	red = chl_val((start >> 24) & 0xFF, (end >> 24) & 0xFF, pct);
	green = chl_val((start >> 16) & 0xFF, (end >> 16) & 0xFF, pct);
	blue = chl_val((start >> 8) & 0xFF, (end >> 8) & 0xFF, pct);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}