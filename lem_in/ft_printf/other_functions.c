/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:20:20 by atrush            #+#    #+#             */
/*   Updated: 2017/01/21 19:20:24 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*unicode(wchar_t c)
{
	unsigned char	*str;
	int				bytes;
	int				i;

	if (c < 0)
		return (NULL);
	bytes = (c < 128) ? 1 : 4;
	bytes = (c > 127 && c < 2048) ? 2 : bytes;
	bytes = (c > 2047 && c < 65536) ? 3 : bytes;
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * (bytes + 1))))
		return (NULL);
	i = -1;
	str[bytes] = '\0';
	if (bytes == 1)
		str[0] = c;
	else
		while (++i < bytes)
			if (i == 0)
				str[i] = (c >> ((bytes - 1) * 6)) + 192 +
					((bytes > 2) ? 32 : 0) + ((bytes == 4) ? 16 : 0);
			else
				str[i] = ((c >> ((bytes - i - 1) * 6)) & 63) + 128;
	return (str);
}

int				ft_atoi(const char *nptr)
{
	int result;

	result = 0;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result);
}

size_t			ft_strlen_u(unsigned char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t			ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_toupper(char **str)
{
	size_t i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] > 96 && (*str)[i] < 123)
			(*str)[i] -= 32;
		i++;
	}
}
