/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:22:05 by atrush            #+#    #+#             */
/*   Updated: 2016/12/05 15:34:00 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
			if (len >= ft_strlen(needle))
				if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
					return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
