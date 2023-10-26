/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:27:05 by arazzok           #+#    #+#             */
/*   Updated: 2023/04/29 16:27:37 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	i = 0;
	if (dst_ptr > src_ptr)
	{
		while (size-- > 0)
			dst_ptr[size] = src_ptr[size];
	}
	else
	{
		while (i < size)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}
