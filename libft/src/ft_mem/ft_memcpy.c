/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:26:44 by arazzok           #+#    #+#             */
/*   Updated: 2023/05/07 13:37:19 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
