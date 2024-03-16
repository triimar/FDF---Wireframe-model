/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:16:20 by tmarts            #+#    #+#             */
/*   Updated: 2022/10/23 18:17:08 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	slen;

	slen = ft_strlen(s);
	while ((slen > 0) && *(s + slen) != (const char)c)
		slen--;
	if (*(s + slen) == (const char)c)
		return ((char *)(s + slen));
	return (0);
}
