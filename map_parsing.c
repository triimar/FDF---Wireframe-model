/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:02:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/09 17:14:59 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_y_axis(fd)
{
	int		y_max;
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (0);
	y_max = 1;
	while (str)
	{
		free(str);
		y_max++;
		str = get_next_line(fd);
	}
}


int main(void)
{
	int		fd1;
	fd1 = open("test", O_RDONLY);
	
	
}

int	map_x_y_z(char *map_name, type_t *coord)
{
	int	fd;
	int	x;
	int	y;

	fd1 = open("test", O_RDONLY);

}