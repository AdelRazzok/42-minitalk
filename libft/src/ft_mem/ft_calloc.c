/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:23:15 by arazzok           #+#    #+#             */
/*   Updated: 2023/05/07 14:41:10 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	if (nmemb == 0 || nmemb == SIZE_MAX || size == 0 || size == SIZE_MAX)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
