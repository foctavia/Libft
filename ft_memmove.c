/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:24:12 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/04 10:31:23 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (d);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char s[] = {67, 68, 67, 68, 69, 0, 45};
	char s2[] = {67, 67, 68, 68, 69, 0, 45};
	
	ft_memmove(s + 1, s, 2);
	printf ("%d\n", memcmp(s, s2, 7));
	memmove(s + 1, s, 2);
	printf ("%d\n", memcmp(s, s2, 7));
	return (0);
}*/
