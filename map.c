/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:02:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/08 21:54:59 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include<stdio.h>

void	ft_initiate(t_map *s_map)
{
	s_map->window = mlx_init(WIDTH, HEIGHT, "test", true);
	if (!s_map->window)
		exit(EXIT_FAILURE);
	s_map->img = mlx_new_image(s_map->window, WIDTH, HEIGHT);
	if (!s_map->img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(s_map->window, s_map->img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	s_map->y_max = 0;
	s_map->x_max = 0;
	s_map->center.x_0 = WIDTH / 2;
	s_map->center.y_0 = HEIGHT / 2;
	s_map->z_abs_max = NULL;
}

double	**ft_map_resize(double **map, int y)
{
	double	**new_map;

	new_map = (int *)malloc((y + ARRAY_SIZE) * sizeof(double *));
	if (!new_map)
		return (free(map), NULL);
	ft_memcpy(new_map, map, (y * (double) sizeof(double *)));
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
		if (!s_map->z_abs_max || \
		abs(s_map->mtrx[s_map->y_max][j].pt_z) > abs(s_map->z_abs_max->pt_z))
			s_map->z_abs_max = &s_map->mtrx[s_map->y_max][j];
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
	s_map->mtrx = malloc(ARRAY_SIZE * sizeof(t_3d *));
	if (!s_map->mtrx)
		return (free(str), NULL);
	y_coeff = 1;
	while (str)
	{
		splits = ft_split(str, ' ');
		if (!splits)
			return (ft_free_all(s_map, splits, str));
		free(str);
		if (s_map->x_max == 0)
			s_map->x_max = arraylen(splits);
		if (s_map->y_max >= ARRAY_SIZE * y_coeff)
		{
			if (ft_map_resize(s_map->mtrx, s_map->y_max) == NULL)
				return (ft_free_split(splits));
			y_coeff++;
		}
		if (ft_get_row(s_map, splits) == NULL)
			return (ft_free_all(s_map, splits, str));
		printf("%s\n", splits[0]);
		ft_free_split(splits);
		str = get_next_line(fd);
		s_map->y_max++;
	}
	return (s_map->mtrx);
}
