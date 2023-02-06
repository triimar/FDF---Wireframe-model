/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:02:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/06 18:08:40 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include<stdio.h>

char	*ft_free_double_p(void **p_p, int len)
{
	int	i;

	i = 0;
	if (!p_p)
		return (NULL);
	while (p_p[i] && i < len)
	{
		free(p_p[i]);
		i++;
	}
	free (p_p);
	return (NULL);
}

static char	*ft_free_split(char **p_p)
{
	int	i;

	i = 0;
	while (p_p[i])
	{
		free(p_p[i]);
		i++;
	}
	free (p_p);
	return (NULL);
}

int	**ft_map_resize(int **map, int y)
{
	int	**new_map;

	new_map = (int *)malloc((y + ARRAY_SIZE) * sizeof(int *));
	if (!new_map)
		return (free(map), NULL);
	ft_memcpy(new_map, map, (y * (int) sizeof(int *)));
	free(map);
	return (new_map);
}

// char	*ft_free_all(t_3d *s_3d, char **split_str, char *str)
// {
// 	if (s_3d->mtrx)
// 		ft_free_double_p(&s_3d->mtrx, s_3d->y_max);
// 	if (split_str)
// 		ft_free_split(split_str);
// 	if (str)
// 		free(str);
// 	return (NULL);
// }

char	*ft_free_all(t_map *s_map, char **split_str, char *str)
{
	if (s_map->mtrx)
		ft_free_double_p(&s_map->mtrx, s_map->y_max);
	if (split_str)
		ft_free_split(split_str);
	if (str)
		free(str);
	return (NULL);
}
// t_3d	*map_x_y_z(char *map_name, t_3d *s_3d)
// {
// 	int		fd;
// 	int		j;
// 	char	*str;
// 	char	**splits;
// 	int		y_coeff;

// 	s_3d->y_max = 0;
// 	s_3d->x_max = 0;
// 	fd = open(map_name, O_RDONLY);
// 	str = get_next_line(fd);
// 	if (!str)
// 		return (0);
// 	s_3d->mtrx = (int *)malloc(ARRAY_SIZE * sizeof(int *));
// 	if (!s_3d->mtrx)
// 		return (free(str), NULL);
// 	y_coeff = 1;
// 	while (str)
// 	{
// 		j = 0;
// 		splits = ft_split(str, ' ');
// 		if (!splits)
// 			return (ft_free_all(&s_3d, splits, str));
// 		free(str);
// 		if (s_3d->x_max == 0)
// 		{
// 			while (splits[s_3d->x_max] != 0 && splits[s_3d->x_max][0] != '\n')
// 				s_3d->x_max++;
// 		}
// 		if (s_3d->y_max >= ARRAY_SIZE * y_coeff)
// 		{
// 			s_3d->mtrx = ft_map_resize(s_3d->mtrx, s_3d->y_max);
// 			if (!s_3d->mtrx)
// 				return (ft_free_split(splits));
// 			y_coeff++;
// 		}
// 		s_3d->mtrx[s_3d->y_max] = malloc(sizeof(double) * s_3d->x_max);
// 		if (!(s_3d->mtrx[s_3d->y_max]))
// 			return (ft_free_all(&s_3d, splits, str));
// 		while (j < s_3d->x_max)
// 		{
// 			s_3d->mtrx[s_3d->y_max][j] = (double)ft_atoi(splits[j]);
// 			// printf("[%d]\n", s_3d->mtrx[s_3d->y_max][j]);
// 			j++;
// 		}
// 		ft_free_split(splits);
// 		str = get_next_line(fd);
// 		s_3d->y_max++;
// 	}
// 	return (s_3d->mtrx);
// }

t_map	*map_x_y_z(char *map_name, t_map *s_map)
{
	int		fd;
	char	*str;
	char	**splits;
	int		y_coeff;
	int		j;

	s_map->y_max = 0;
	s_map->x_max = 0;
	s_map->z_abs_max = NULL;
	fd = open(map_name, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	s_map->mtrx = malloc(ARRAY_SIZE * sizeof(t_3d *));
	if (!s_map->mtrx)
		return (free(str), NULL);
	y_coeff = 1;
	while (str)
	{
		j = 0;
		splits = ft_split(str, ' ');
		if (!splits)
			return (ft_free_all(&s_map, splits, str));
		free(str);
		if (s_map->x_max == 0)
		{
			while (splits[s_map->x_max] != 0 && splits[s_map->x_max][0] != '\n')
				s_map->x_max++;
		}
		if (s_map->y_max >= ARRAY_SIZE * y_coeff)
		{
			s_map->mtrx = ft_map_resize(s_map->mtrx, s_map->y_max);
			if (!s_map->mtrx)
				return (ft_free_split(splits));
			y_coeff++;
		}
		s_map->mtrx[s_map->y_max] = malloc(sizeof(t_3d) * s_map->x_max);
		if (!(s_map->mtrx[s_map->y_max]))
			return (ft_free_all(&s_map, splits, str));
		while (j < s_map->x_max)
		{
			s_map->mtrx[s_map->y_max][j].pt_x = (float)j;
			s_map->mtrx[s_map->y_max][j].pt_y = (float)s_map->y_max;
			s_map->mtrx[s_map->y_max][j].pt_z = (float)ft_atoi(splits[j]);
			if (s_map->z_abs_max == 0 || abs(s_map->mtrx[s_map->y_max][j].pt_z) > abs(s_map->z_abs_max->pt_z))
				s_map->z_abs_max = &s_map->mtrx[s_map->y_max][j];
			j++;
		}
		ft_free_split(splits);
		str = get_next_line(fd);
		s_map->y_max++;
	}
	return (s_map->mtrx);
}