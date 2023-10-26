/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:35:30 by arazzok           #+#    #+#             */
/*   Updated: 2023/05/07 15:51:13 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*start_check(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str == 0)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static int	len_check(char const *s, unsigned int start, size_t len)
{
	if ((ft_strlen(s) - start) < len)
		return ((ft_strlen(s) - start));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (ft_strlen(s) < start)
		return (start_check());
	str = malloc(sizeof(char) * (len_check(s, start, len) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
