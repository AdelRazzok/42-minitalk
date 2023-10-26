/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:08:25 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/12 18:43:50 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_format(va_list *args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, uintptr_t));
	else if (format == '%')
		len += ft_print_char('%');
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(*args, unsigned int), format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	*args_ptr;
	int		len;

	va_start(args, format);
	args_ptr = &args;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_handle_format(args_ptr, *(format + 1));
			format++;
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (len);
}
