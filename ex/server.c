/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 06:30:24 by mlaval            #+#    #+#             */
/*   Updated: 2023/05/07 16:20:19 by mlaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
	static int	result = 0;
	static int	p = 128;
	static char	*str;

	if (signum == SIGUSR1)
		result += p;
	p /= 2;
	if (p == 0)
	{
		if (result == 0)
		{
			ft_printf("Reception from client %d.\n\n", siginfo->si_pid);
			ft_printf("Notification : %s\n\n", str);
			free(str);
			str = NULL;
			kill(siginfo->si_pid, SIGUSR1);
		}
		if (result != 0)
			str = ft_strjoin(str, result);
		result = 0;
		p = 128;
	}
	(void)context;
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		handle_error(4);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		handle_error(1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_sigaction = handle_client_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server launched.\nServer PID = %d", getpid());
	ft_printf("\nWaiting for client signal...\n\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		handle_error(3);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		handle_error(3);
	while (1)
		pause();
	return (0);
}
