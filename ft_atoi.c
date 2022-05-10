/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:39:17 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/04 15:57:11 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	int		nbr;
	char	*str;

	str = (char *)nptr;
	i = 0;
	neg = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	nbr = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = ((nbr * 10) + (str[i] - '0'));
		i++;
	}
	return (nbr * neg);
}
