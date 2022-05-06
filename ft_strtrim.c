/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:40:15 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/05 17:40:19 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	count_len(char const *s1, char const *set)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if (!check_set(set, s1[i]))
			len++;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	len;
	char	*new;

	len = count_len(s1, set);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!check_set(set, s1[i]))
		{
			new[j] = s1[i];
			j++;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}
