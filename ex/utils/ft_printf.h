/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:57:27 by mlaval            #+#    #+#             */
/*   Updated: 2023/04/24 21:34:09 by mlaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define MIN_INT -2147483648
# define MAX_INT 2147483647

int		ft_printf(const char *format, ...);
int		ft_nbrbase(unsigned long nbr, char *base, int fd, int ptr);
int		ft_format(va_list args, char c);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_un_fd(unsigned int n, int fd);
int		ft_putnbr_fd(int n, int fd);
#endif