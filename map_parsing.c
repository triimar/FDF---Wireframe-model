/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:02:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/19 19:40:47 by tmarts           ###   ########.fr       */
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


int	map_x_y_z(char *map_name)
{
	int		fd;
	int		x;
	int		j;
	char	*str;
	char	**split_str;
	int		*z_val;
	int 	i;

	i = 0;
	// y_max = 0;
	fd = open(map_name, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	printf("[%s]\n", str);
	printf("_________________________________________\n");
	if (str)
	{
		x = 0;
		j = 0;
		split_str = ft_split(str, ' ');
		free(str);
		while (split_str[x] != NULL)
		{
			printf("[%s]\n", split_str[x]);
			x++;
		}	
		printf(">>>>>[%d]\n", x);
		z_val = (int *)malloc(sizeof(int) * x);
		if (!z_val)
			return (0);
		while (j < x)
		{
			z_val[j] = ft_atoi(split_str[j]);
			j++;
		}
		printf("_________________________________________\n");
		while (i < x)
		{
			printf("[%d]\n", z_val[i]);
			i++;
		}	
	}
}

int	main(void)
{
	map_x_y_z("42.fdf");
}