/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:19:15 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/26 15:37:11 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include "../libft/include/libft.h"
# include <signal.h>

char    *str_add_char(char *s1, char c);
void    error_handler(int status);
int     is_str_digit(char *str);

#endif
