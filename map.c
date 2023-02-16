/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:02:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/16 17:38:26 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_map_resize(double **map, int y)
{
	int	**new_map;

	new_map = malloc((y + ARRAY_SIZE) * sizeof(t_3d *));
	if (!new_map)
		return (ft_free_double_p(map, y));
	ft_memcpy(new_map, map, y * sizeof(t_3d *));
	free(map);
	return (new_map);
}

t_3d	*ft_get_row(t_map *s_map, char **splits)
{
	int	j;

	j = 0;
	s_map->mtrx[s_map->y_max] = malloc(sizeof(t_3d) * s_map->x_max);
	if (!(s_map->mtrx[s_map->y_max]))
		return (NULL);
	while (j < s_map->x_max)
	{
		s_map->mtrx[s_map->y_max][j].pt_x = (double)j;
		s_map->mtrx[s_map->y_max][j].pt_y = (double)s_map->y_max;
		s_map->mtrx[s_map->y_max][j].pt_z = (double)ft_atoi(splits[j]);
		if (!s_map->pt_z_max || \
		s_map->mtrx[s_map->y_max][j].pt_z > s_map->pt_z_max->pt_z)
			s_map->pt_z_max = &s_map->mtrx[s_map->y_max][j];
		if (!s_map->pt_z_min || \
		s_map->mtrx[s_map->y_max][j].pt_z < s_map->pt_z_min->pt_z)
			s_map->pt_z_min = &s_map->mtrx[s_map->y_max][j];
		j++;
	}
	return (s_map->mtrx[s_map->y_max]);
}

static int	arraylen(char **splits)
{
	int	x;

	x = 0;
	while (splits[x] != 0 && splits[x][0] != '\n')
		x++;
	return (x);
}

t_map	*map_x_y_z(int fd, t_map *s_map)
{
	char	*str;
	char	**splits;
	int		y_coeff;

	str = get_next_line(fd);
	if (!str)
		return (0);
	s_map->mtrx = malloc(ARRAY_SIZE * sizeof(int *));
	if (!s_map->mtrx)
		return (free(str), NULL);
	y_coeff = 1;
	while (str)
	{
		splits = ft_split(str, ' ');
		if (!splits)
			return (ft_free_all(s_map, 0, str));
		free(str);
		if (s_map->x_max == 0)
			s_map->x_max = arraylen(splits);
		if (s_map->y_max >= ARRAY_SIZE * y_coeff)
		{
			s_map->mtrx = ft_map_resize(s_map->mtrx, s_map->y_max);
			if (!s_map->mtrx)
				return (ft_free_split(splits));
			y_coeff++;
		}
		if (ft_get_row(s_map, splits) == NULL)
			ft_free_all(s_map, splits, 0);
		ft_free_split(splits);
		str = get_next_line(fd);
		s_map->y_max++;
	}
	return (s_map->mtrx);
}
