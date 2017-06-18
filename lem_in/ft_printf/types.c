/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:20:44 by atrush            #+#    #+#             */
/*   Updated: 2017/01/21 19:20:48 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_s(va_list args, int frmt[9])
{
	char	*str;
	size_t	size;

	frmt[3] = 1;
	str = va_arg(args, char *);
	if (!str)
		size = 6;
	else
		size = ft_strlen(str);
	return (print(str, frmt, (((size_t)frmt[1] < size) &&
		frmt[1] != -1) ? (size_t)frmt[1] : size));
}

int		type_p(va_list args, int frmt[9])
{
	int					tmp;
	char				*str;

	frmt[3] = 3;
	if (!(str = ft_itoa_u((unsigned long int)va_arg(args, void *), 16)))
		return (-1);
	if (frmt[1] == 0 && str[0] == '0' && str[1] == '\0')
		str[0] = '\0';
	tmp = print(str, frmt, ft_strlen(str));
	free(str);
	return (tmp);
}

int		type_c(va_list args, int frmt[9], int flag)
{
	unsigned char ch;

	frmt[3] = 4;
	if (flag)
		ch = '%';
	else
		ch = va_arg(args, int);
	return (print(&ch, frmt, 1));
}

int		type_ls(va_list args, int frmt[9], int i)
{
	wchar_t			*src;
	unsigned char	*str;
	unsigned char	*uncd;

	str = NULL;
	if ((src = va_arg(args, wchar_t*)))
		while (src[i] && (frmt[1] == -1 || frmt[1] > i))
		{
			if (!(uncd = unicode(src[i++])))
				return (-1);
			if (!(ft_strrealcat(&str, &uncd)))
			{
				free(uncd);
				return (-1);
			}
			free(uncd);
		}
	if (src && src[0] == '\0')
		if (!(str = unicode(src[0])))
			return (-1);
	i = (str) ? ft_strlen_u(str) : 6;
	i = (frmt[1] != -1 && frmt[1] < i) ? frmt[1] : i;
	i = print(str, frmt, i);
	free(str);
	return (i);
}

int		type_lc(va_list args, int frmt[9])
{
	wchar_t			c;
	unsigned char	*str;
	int				tmp;

	frmt[3] = 5;
	c = va_arg(args, wint_t);
	if (!(str = unicode(c)))
		return (-1);
	tmp = print(str, frmt, ft_strlen_u(str));
	free(str);
	if (tmp <= 0)
		return (1);
	return (tmp);
}
