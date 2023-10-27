/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 02:19:32 by mlaval            #+#    #+#             */
/*   Updated: 2023/05/05 14:25:58 by mlaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrbase(unsigned long nbr, char *base, int fd, int ptr)
{
	unsigned long	size;
	unsigned long	nb;
	int				len;

	len = 0;
	nb = nbr;
	if (ptr)
	{
		if (nbr == 0)
			return (len += ft_putstr_fd("(nil)", fd));
		len += ft_putstr_fd("0x", fd);
		ptr = 0;
	}
	size = ft_strlen(base);
	if (nb > size - 1)
	{
		len += ft_nbrbase(nb / size, base, fd, ptr);
	}
	len += ft_putchar_fd(base[nb % size], fd);
	return (len);
}

int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		len += ft_nbrbase(va_arg(args, unsigned long), "0123456789abcdef", 1,
				1);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		len += ft_putnbr_un_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789abcdef", 1, 0);
	else if (c == 'X')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789ABCDEF", 1, 0);
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(arguments, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			len += ft_format(arguments, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
	}
	va_end(arguments);
	return (len);
}
