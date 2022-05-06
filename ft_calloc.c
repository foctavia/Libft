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

	if (nmemb == 0 || size == 0 || nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	rtr = malloc(nmemb * size);
	if (!rtr)
		return (NULL);
	ft_bzero(rtr, nmemb * size);
	return (rtr);
}
