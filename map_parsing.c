/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:02:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/22 21:58:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int get_y_axis(fd)
// {
// 	int		y_max;
// 	char	*str;

// 	str = get_next_line(fd);
// 	if (!str)
// 		return (0);
// 	y_max = 1;
// 	while (str)
// 	{
// 		free(str);
// 		y_max++;
// 		str = get_next_line(fd);
// 	}
// }
// typedef struct s_coords {
// 	int	**mtrx;
// 	int	x_max;
// 	int	y_max;
// }	t_coords;

// int	y_maxval(int fd)
// {
// 	int		y;
// 	char	*str;

// 	str = get_next_line(fd);
// 	y = 0;
// 	while (str)
// 	{
// 		y++;
// 		str = get_next_line(fd);
// 	}
// 	return (y);
// }

char	*ft_free_double_p(char **p_p, int len)
{
	len--;
	while (len >= 0 && p_p[len])
	{
		free(p_p[len]);
		len--;
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

char	*ft_free_all(int **map, int y, char **split_str, int x, char *str)
{
	if (map)
		ft_free_double_p(map, y);
	if (split_str)
		ft_free_double_p(split_str, y);
	if (str)
		free(str);
	return (NULL);
}

int	**map_x_y_z(char *map_name)
{
	int		fd;
	int		j;
	char	*str;
	char	**split_str;
	int		y_coeff;
	int		x;
	int 	y;
	int		**map;


	y = 0;
	x = 0;
	fd = open(map_name, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	map = (int *)malloc(ARRAY_SIZE * sizeof(int *));
	if (!map)
		return (free(str), NULL);
	y_coeff = 1;
	while (str)
	{
		j = 0;
		split_str = ft_split(str, ' ');
		if (!split_str)
			return (ft_free_all(map, (y - 1), split_str, x, str));
		free(str);
		if (x == 0)
		{
			while (split_str[x] != NULL)
				x++;
		}
		if (y >= ARRAY_SIZE * y_coeff)
		{
			map = ft_map_resize(map, y);
			if (!map)
				return (ft_free_double_p(split_str, x));
			y_coeff++;
		}
		map[y] = (int *)malloc(sizeof(int) * x);
		if (!(map[y]))
			return (ft_free_all(map, y, split_str, x, str));
		while (j < x)
		{
			map[y][j] = ft_atoi(split_str[j]);
			j++;
		}
		ft_free_double_p(split_str, x);
		str = get_next_line(fd);
		y++;
	}
	// int i = 0;
	// int printing = 0;
	// while (i < y)
	// {
	// 	printing = 0;
	// 	while (printing < x)
	// 	{
	// 		printf("[%d]", map[i][printing]);
	// 		printing++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// 	printf("%d\n", i);
	// 	printf(">>>>>>X[%d]\n", x);
	// 	printf(">>>>>>Y[%d]\n", y);
	// }
	ft_free_double_p(map, y);
	return (NULL);
}

int	main(void)
{
	 map_x_y_z("test_maps/20-60.fdf");
	 system("leaks FDF.a");
}

	// printf(">>>>>>[%d]\n", y);
	// int i = 0;
	// int printing = 0;
	// while (i < y)
	// {
	// 	printing = 0;
	// 	while (printing < x)
	// 	{
	// 		printf("[%d]", map[i][printing]);
	// 		printing++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// 	printf("%d\n", i);
	// }