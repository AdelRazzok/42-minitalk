/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:35:26 by arazzok           #+#    #+#             */
/*   Updated: 2023/05/07 12:35:27 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_getword(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = ft_substr(s, 0, i);
	if (!word)
		return (NULL);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	nb_word;
	size_t	i;

	nb_word = ft_countwords(s, c);
	res = malloc(sizeof(*res) * (nb_word + 1));
	if (!s || !res)
		return (NULL);
	i = 0;
	while (i < nb_word)
	{
		while (*s && *s == c)
			s++;
		res[i] = ft_getword(s, c);
		if (!res[i])
			return (NULL);
		s += ft_strlen(res[i]);
		i++;
	}
	res[nb_word] = NULL;
	return (res);
}
