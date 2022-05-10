/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:41:56 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/06 12:43:11 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int nbr)
{
	int			len;
	long int	n;

	n = nbr;
	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	putnbr(int nbr, char *str, int i)
{
	long int	n;

	n = nbr;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n > 9)
		putnbr(n / 10, str, i - 1);
	str[i] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	putnbr(n, str, len - 1);
	str[len] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}*/
