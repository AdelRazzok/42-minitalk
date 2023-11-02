/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:16:47 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/26 15:54:39 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    char_to_bin(char c, int pid)
{
	int i;

	i = 128;
	while (i >= 1)
	{
		if (i & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_handler(3);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_handler(3);
		}
		i /= 2;
		usleep(100);
	}
}

void    str_to_bin(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bin(str[i], pid);
		i++;
	}
	char_to_bin('\0', pid);
}

void	handle_server_signal(int signum, siginfo_t *siginfo, void *context)
{
	(void)	siginfo;
	(void)	context;
	if (signum == SIGUSR1)
		printf("Signal received successfully.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (0);
	}
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_sigaction = handle_server_signal;
	sa.sa_flags = SA_SIGINFO;
	pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler(2);
	if (!is_str_digit(argv[1]) || pid < 0)
	{
		ft_printf("pid = %d\n", pid);
		error_handler(1);
	}
	ft_printf("Trying to send a signal to : %d\n", pid);
	str_to_bin(argv[2], pid);
	return (0);
}
