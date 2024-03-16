/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:36:55 by tmarts            #+#    #+#             */
/*   Updated: 2022/10/28 18:00:27 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long		intvalue;
	int				neg_pos;

	intvalue = 0;
	neg_pos = 1;
	while ((*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str == '-')
	{
		neg_pos = -1;
		str++;
	}	
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		intvalue = intvalue * 10 + (*str - '0');
		if (intvalue < 0 && neg_pos < 0)
			return (0);
		if (intvalue < 0 && neg_pos > 0)
			return (-1);
		str++;
	}
	return ((int)(intvalue * neg_pos));
}
