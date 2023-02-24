/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:58:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/24 19:07:18 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_free_double_p(t_3d **p_p, int len)
{
	int	i;

	i = 0;
	if (!p_p)
		return (NULL);
	while (i < len && p_p[i])
	{
		free(p_p[i]);
		i++;
	}
	free (p_p);
	p_p = NULL;
	return (NULL);
}

char	*ft_free_split(char **p_p)
{
	int	i;

	i = 0;
	if (!p_p)
		return (NULL);
	while (p_p[i])
	{
		free(p_p[i]);
		i++;
	}
	free (p_p);
	return (NULL);
}

char	*ft_free_all(t_map *s_map, char **split_str, char *str)
{
	if (s_map != 0 && s_map->mtrx)
		ft_free_double_p(s_map->mtrx, s_map->y_max);
	if (split_str)
		ft_free_split(split_str);
	if (str)
		free(str);
	return (NULL);
}

void	error_msg(int error)
{
	if (error == 1)
		ft_printf("ERROR: incorrect number of arguments\n");
	if (error == 2)
		ft_printf("ERROR: incorrect file name or invalid fd\n");
	if (error == 3)
		ft_printf("ERROR: MLX failure\n");
	if (error == 4)
		ft_printf("ERROR: map parsing failure\n");
}
