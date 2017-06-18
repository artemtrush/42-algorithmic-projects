/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:29:11 by atrush            #+#    #+#             */
/*   Updated: 2016/12/01 18:05:33 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	unsigned const char	*b;
	int					i;

	a = dest;
	b = src;
	if (a < b)
		i = 1;
	else
	{
		i = -1;
		a = a + n - 1;
		b = b + n - 1;
	}
	while (n > 0)
	{
		*a = *b;
		a = a + i;
		b = b + i;
		n--;
	}
	return (dest);
}
