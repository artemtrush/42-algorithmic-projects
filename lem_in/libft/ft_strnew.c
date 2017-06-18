/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:14:03 by atrush            #+#    #+#             */
/*   Updated: 2016/12/08 15:41:11 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char*)malloc(size + 1);
	if (s)
	{
		ft_bzero(s, size);
		s[size] = '\0';
		return ((char*)s);
	}
	return (NULL);
}
