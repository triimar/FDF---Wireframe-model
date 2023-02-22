/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:39:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/22 18:05:28 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	position_pct(double min, double max, double current)
{
	double	position;
	double	range;
	double	percentage;

	range = max - min;
	position = current - min;
	percentage = position / range;
	return (percentage);
}

int	chl_val(int st_rgba, int end_rgba, double position_pct)
{
	int	current;

	current = (int)((1 - position_pct) * st_rgba + position_pct * end_rgba);
	return (current);
}

int	get_rgba(double pct, int st_rgba, int e_rgba)
{
	int		red;
	int		green;
	int		blue;

	if (st_rgba == e_rgba)
		return (st_rgba);
	red = chl_val((st_rgba >> 24) & 0xFF, (e_rgba >> 24) & 0xFF, pct);
	green = chl_val((st_rgba >> 16) & 0xFF, (e_rgba >> 16) & 0xFF, pct);
	blue = chl_val((st_rgba >> 8) & 0xFF, (e_rgba >> 8) & 0xFF, pct);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}
