/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:39:09 by atrush            #+#    #+#             */
/*   Updated: 2016/12/01 18:49:28 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(ft_strlen(s) + 1);
	if (str)
	{
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = s[i];
	}
	return (str);
}
