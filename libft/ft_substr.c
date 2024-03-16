/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:12:44 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/02 21:11:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	size_t	s_len;
	char	*sub;

	s_len = ft_strlen(s);
	size = len;
	if (s_len <= start)
		size = 0;
	else if (s_len < len || s_len < len + start)
		size = s_len - start;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	if (i == size)
			sub[i] = '\0';
	return (sub);
}
