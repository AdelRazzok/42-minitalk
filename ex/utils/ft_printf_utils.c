/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:47:20 by mlaval            #+#    #+#             */
/*   Updated: 2023/05/05 14:26:00 by mlaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return ((size_t)count);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	while (s[++i])
		len += ft_putchar_fd(s[i], fd);
	return (len);
}

int	ft_putnbr_un_fd(unsigned int n, int fd)
{
	unsigned int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_un_fd(n / 10, fd);
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == MIN_INT)
		len += ft_putstr_fd("-2147483648", fd);
	else if (n == MAX_INT)
		len += ft_putstr_fd("2147483647", fd);
	else
	{
		if (n < 0)
		{
			len += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
			len += ft_putnbr_fd(n / 10, fd);
		len += ft_putchar_fd((n % 10) + '0', fd);
	}
	return (len);
}
