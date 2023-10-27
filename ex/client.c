/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:52:57 by mlaval            #+#    #+#             */
/*   Updated: 2023/05/07 16:21:29 by mlaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(char c, int pid)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (i & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				handle_error(4);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				handle_error(4);
		}
		i = i / 2;
		usleep(5000);
	}
}

void	str_to_char(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		char_to_bin(str[i], pid);
	char_to_bin('\0', pid);
}

void	handle_server_signal(int signum, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		printf("Validation from server.\n");
}

int	ft_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		handle_error(1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_sigaction = handle_server_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		handle_error(3);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		handle_error(3);
	if (!ft_isdigit(argv[1]) || ft_atoi(argv[1]) < 0)
		handle_error(2);
	ft_printf("Attempt to send signal to server %d...\n", ft_atoi(argv[1]));
	str_to_char(argv[2], ft_atoi(argv[1]));
	return (0);
}
