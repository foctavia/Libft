/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:13:06 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/04 16:48:34 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtr;

	if (nmemb * size / size != nmemb)
		return (NULL);
	if (!nmemb || !size)
	{
		size = 1;
		nmemb = 1;
	}
	rtr = malloc(nmemb * size);
	if (!rtr)
		return (NULL);
	ft_bzero(rtr, nmemb * size);
	return (rtr);
}
