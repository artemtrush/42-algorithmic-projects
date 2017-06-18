/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:16:29 by atrush            #+#    #+#             */
/*   Updated: 2016/12/06 12:31:57 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s)
	{
		new = ft_strnew(len);
		if (new)
		{
			while (i < len)
			{
				new[i] = s[start + i];
				i++;
			}
			return (new);
		}
	}
	return (NULL);
}
