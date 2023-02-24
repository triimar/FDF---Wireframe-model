/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:57:21 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/24 01:56:16 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	s_map;
	int		fd;

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (EXIT_FAILURE);
	ft_initiate(&s_map);
	if (!map_parse(fd, &s_map))
		return (EXIT_FAILURE);
	close(fd);
	ft_defaults(&s_map);
	draw_all(&ft_iso_rot, &s_map);
	mlx_scroll_hook(s_map.window, (mlx_scrollfunc)scroll_scale, (void *)&s_map);
	mlx_key_hook(s_map.window, &single_key_h, (void *)&s_map);
	mlx_loop_hook(s_map.window, (void (*)(void *))genhook_re, &s_map);
	mlx_loop(s_map.window);
	mlx_delete_image(s_map.window, s_map.img);
	mlx_terminate(s_map.window);
	ft_free_all(&s_map, 0, 0);
	// system("leaks fdf");
	return (EXIT_SUCCESS);
}
