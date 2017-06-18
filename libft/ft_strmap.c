/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:12:17 by atrush            #+#    #+#             */
/*   Updated: 2016/12/05 19:44:12 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	i = 0;
	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		if (new)
		{
			while (s[i])
			{
				new[i] = f(s[i]);
				i++;
			}
			return (new);
		}
	}
	return (NULL);
}
