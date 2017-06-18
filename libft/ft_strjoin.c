/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:32:58 by atrush            #+#    #+#             */
/*   Updated: 2016/12/07 16:03:42 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!*s1 && !*s2)
	{
		if (!(new = (char*)malloc(sizeof(char))))
			return (NULL);
		*new = '\0';
	}
	else
	{
		if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcat(new, s1);
		ft_strcat(new, s2);
	}
	return (new);
}
