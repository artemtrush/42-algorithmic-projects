/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:45:40 by atrush            #+#    #+#             */
/*   Updated: 2016/12/08 14:56:13 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *s;

	if (size > 0)
	{
		s = (void*)malloc(size);
		if (s)
		{
			ft_bzero(s, size);
			return ((void*)s);
		}
	}
	return (NULL);
}
