/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:30:14 by atrush            #+#    #+#             */
/*   Updated: 2016/12/08 14:43:54 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int max;

	i = 0;
	max = -1;
	if ((char)c == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char)c)
			max = i;
		i++;
	}
	if (max >= 0)
		return ((char*)(&s[max]));
	return (NULL);
}
