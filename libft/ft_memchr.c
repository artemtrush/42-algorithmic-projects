/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:08:31 by atrush            #+#    #+#             */
/*   Updated: 2016/12/01 18:21:14 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned const char	*a;

	a = arr;
	while (n > 0)
	{
		if (a[0] == (unsigned char)c)
			return ((char*)a);
		a++;
		n--;
	}
	return (NULL);
}
