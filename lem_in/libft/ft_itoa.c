/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:08:41 by atrush            #+#    #+#             */
/*   Updated: 2016/12/06 17:42:35 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_sizenum(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	else
		n = -n;
	while (n != 0)
	{
		size--;
		str[size] = 48 - (n - ((n / 10) * 10));
		n = n / 10;
	}
	return (str);
}
