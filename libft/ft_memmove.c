/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:14:44 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/03 14:23:42 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*to;
	char	*from;

	to = (char *)dst;
	from = (char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (to > from && to - from < (int)len)
	{
		while (len != 0)
		{
			*(to + len - 1) = *(from + len - 1);
			len--;
		}
	}
	else
	{
		while (len != 0)
		{
			*(to++) = *(from++);
			len--;
		}
	}
	return (dst);
}
