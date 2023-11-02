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

void	signal_handler(int signal, siginfo_t *siginfo, void *context)
{
	static int	res = 0;
	static int	pow = 128;
	static char	*str;
	(void)		context;

	if (signal == SIGUSR1)
		res += pow;
	pow /= 2;
	if (pow == 0)
	{
		if (res == 0)
		{
			ft_printf("Signal received from : %d.\n", siginfo->si_pid);
			ft_printf("Message : %s\n", str);
			free(str);
			str = NULL;
			kill(siginfo->si_pid, SIGUSR1);
		}
		else
			str = str_add_char(str, res);
		res = 0;
		pow = 128;
	}
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		error_handler(3);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", (int)getpid());
	ft_printf("Waiting for a signal...\n");
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler(2);
	while (1)
		pause();
	return (0);
}
