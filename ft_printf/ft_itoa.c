/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:19:49 by atrush            #+#    #+#             */
/*   Updated: 2017/01/21 19:19:54 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcat(unsigned char **str1, unsigned char **str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*str1 || !*str2)
		return (0);
	while ((*str1)[i])
		i++;
	while ((*str2)[j])
		(*str1)[i++] = (*str2)[j++];
	(*str1)[i] = '\0';
	return (1);
}

int		ft_strrealcat(unsigned char **str1, unsigned char **str2)
{
	unsigned char	*tmp;

	tmp = NULL;
	if (*str1)
	{
		if (!(tmp = (unsigned char*)malloc(sizeof(unsigned char)
						* (ft_strlen_u(*str1) + ft_strlen_u(*str2) + 1))))
		{
			free(*str1);
			return (0);
		}
		tmp[0] = '\0';
		ft_strcat(&tmp, str1);
		ft_strcat(&tmp, str2);
		free(*str1);
		*str1 = tmp;
		return (1);
	}
	if (!(*str1 = (unsigned char*)malloc(sizeof(unsigned char)
					* (ft_strlen_u(*str2) + 1))))
		return (0);
	(*str1)[0] = '\0';
	ft_strcat(str1, str2);
	return (1);
}

char	*ft_itoa_ll(long long int value, int base)
{
	size_t				size;
	char				*str;
	long long int		tmp;

	tmp = value;
	size = (value <= 0) ? 1 : 0;
	while (++size != 0 && tmp != 0)
		tmp = tmp / base;
	if (!(str = (char*)malloc(sizeof(char) * size--)))
		return (NULL);
	str[size--] = '\0';
	if (value == 0)
		str[0] = '0';
	if (value < 0 && base == 10)
		str[0] = '-';
	while (value != 0)
	{
		tmp = value % base;
		tmp = (tmp < 0) ? -tmp : tmp;
		if (tmp > 9)
			tmp = tmp + 39;
		str[size--] = tmp + 48;
		value = value / base;
	}
	return (str);
}

char	*ft_itoa_u(unsigned long long int value, int base)
{
	size_t					size;
	char					*str;
	unsigned long long int	tmp;

	tmp = value;
	size = (value == 0) ? 1 : 0;
	while (++size != 0 && tmp != 0)
		tmp = tmp / base;
	if (!(str = (char*)malloc(sizeof(char) * size--)))
		return (NULL);
	str[size--] = '\0';
	if (value == 0)
		str[0] = '0';
	while (value != 0)
	{
		tmp = value % base;
		if (tmp > 9)
			tmp = tmp + 39;
		str[size--] = tmp + 48;
		value = value / base;
	}
	return (str);
}

char	*ft_itoa_size_t(size_t value, int base)
{
	size_t	size;
	char	*str;
	size_t	tmp;

	tmp = value;
	size = (value == 0) ? 1 : 0;
	while (++size != 0 && tmp != 0)
		tmp = tmp / base;
	if (!(str = (char*)malloc(sizeof(char) * size--)))
		return (NULL);
	str[size--] = '\0';
	if (value == 0)
		str[0] = '0';
	while (value != 0)
	{
		tmp = value % base;
		if (tmp > 9)
			tmp = tmp + 39;
		str[size--] = tmp + 48;
		value = value / base;
	}
	return (str);
}
