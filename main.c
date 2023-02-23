/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:57:21 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/23 18:14:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	s_map;
	int		fd;

	if (argc != 2)
		return (NULL); //error message here
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (NULL); //need error message here
	ft_initiate(&s_map);
	map_parse(fd, &s_map);
	close(fd);
	ft_defaults(&s_map);
	draw_all(&ft_iso_rot, &s_map);
	mlx_scroll_hook(s_map.window, &scroll_scale, &s_map);
	mlx_key_hook(s_map.window, &single_key_h, &s_map);
	mlx_loop_hook(s_map.window, (void (*)(void *))genhook_re, &s_map);
	mlx_loop(s_map.window);
	mlx_delete_image(s_map.window, s_map.img);
	mlx_terminate(s_map.window);
	ft_free_all(&s_map, 0, 0);
	system("leaks fdf");
	return (EXIT_SUCCESS);
}
