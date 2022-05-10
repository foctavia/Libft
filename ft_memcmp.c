/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:12:46 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/04 14:09:08 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] == str2[i] && i < (n - 1))
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = {0, 0, 127, 0};
	char	s1[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s, s1, 4));
	printf("%d\n", memcmp(s, s1, 4));
	return (0);
}*/
