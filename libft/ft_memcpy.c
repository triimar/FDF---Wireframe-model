/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:35:33 by tmarts            #+#    #+#             */
/*   Updated: 2022/12/12 21:29:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*to;
	char	*from;

	if (dst == 0 && src == 0)
		return (0);
	to = (char *)dst;
	from = (char *)src;
	while (n != 0)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	return (dst);
}
