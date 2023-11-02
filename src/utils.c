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

char    *str_add_char(char *str, char c)
{
    char    *res;
    int     len;
    int     i;

    if (!str)
    {
        str = malloc(sizeof(char) * 1);
        if (!str)
            return (NULL);
        str[0] = '\0';
    }
    len = ft_strlen(str) + 2;
    res = (char *)malloc(sizeof(char) * len);
    if (!res)
        return (NULL);
    i = 0;
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
    res[i] = c;
    res[i + 1] = '\0';
    free(str);
    return (res);
}

void    error_handler(int status)
{
    if (status == 1)
        ft_printf("Error.\nInvalid PID.\n");
    else if (status == 2)
        ft_printf("Error.\nSigaction error.\n");
    else if (status == 3)
        ft_printf("Error.\nSignal error.\n");
    else
        ft_printf("Error.\n");
    exit(0);
}

int is_str_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
