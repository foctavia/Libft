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
	size_t	i;
	size_t	trim;
	size_t	lensrc;
	size_t	ttl_i;

	i = 0;
	lensrc = ft_strlen(s1);
	ttl_i = lensrc - 1;
	trim = 0;
	while (s1[i] && check_set(set, s1[i]))
	{
		i++;
		trim++;
	}
	while (ttl_i > i && check_set(set, s1[ttl_i]))
	{
		trim++;
		ttl_i--;
	}
	return (lensrc - trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	j;
	size_t	len;
	char	*new;

	len = count_len(s1, set);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && check_set(set, s1[i]))
		i++;
	while (s1[i] && j < len)
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	new[j] = 0;
	return (new);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf ("%s\n", ft_strtrim(argv[1], argv[2]));
// 	return (0);
// }