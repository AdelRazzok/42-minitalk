/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:33:31 by arazzok           #+#    #+#             */
/*   Updated: 2023/05/07 13:28:35 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*el;
	int		count;

	el = lst;
	count = 0;
	while (el)
	{
		el = el->next;
		count++;
	}
	return (count);
}
