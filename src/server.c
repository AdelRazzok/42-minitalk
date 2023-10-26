/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:16:44 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/26 15:35:41 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static unsigned char	c;
	static int				bit;

	c |= (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a signal...\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
