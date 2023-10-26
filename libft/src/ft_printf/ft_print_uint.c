/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:08:30 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/12 18:43:45 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_countdigits(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_print_uint(unsigned int nbr)
{
	int		len;
	char	*num;

	len = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	num = ft_uitoa(nbr);
	len = ft_print_str(num);
	free(num);
	return (len);
}
