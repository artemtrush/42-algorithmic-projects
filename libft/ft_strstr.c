/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:54:02 by atrush            #+#    #+#             */
/*   Updated: 2016/12/03 19:43:30 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
				return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
