/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:41:18 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/12 18:42:57 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_hexa(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static void	ft_put_hexa(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_put_hexa(nb / 16, format);
		ft_put_hexa(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hexa(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	ft_put_hexa(nb, format);
	return (ft_count_hexa(nb));
}
