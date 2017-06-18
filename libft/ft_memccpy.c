/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:13:54 by atrush            #+#    #+#             */
/*   Updated: 2016/12/01 17:54:31 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*a;
	unsigned const char	*b;

	a = dest;
	b = src;
	while (n > 0)
	{
		*a = *b;
		if (a[0] == (unsigned char)c)
		{
			a++;
			return (a);
		}
		a++;
		b++;
		n--;
	}
	return (0);
}
