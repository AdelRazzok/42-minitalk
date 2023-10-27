/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:21:48 by mlaval            #+#    #+#             */
/*   Updated: 2023/05/07 16:13:03 by mlaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			n = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * res);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*res;
	int		t_len;
	int		i;

	i = -1;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	t_len = ft_strlen(s1) + 2;
	res = (char *)malloc(sizeof(char) * t_len);
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	res[i] = s2;
	res[i + 1] = '\0';
	free(s1);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*add;

	add = s;
	while (n > 0)
	{
		*add = 0;
		add++;
		n--;
	}
}

void	handle_error(int status)
{
	if (status == 1)
		ft_printf("Invalid number of arguments.\n");
	else if (status == 2)
		ft_printf("Invalid PID.\n");
	else if (status == 3)
		ft_printf("Sigaction error.\n");
	else if (status == 4)
		ft_printf("Signal error.\n");
	exit (0);
}
