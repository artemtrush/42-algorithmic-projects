/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependet_on_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:04:36 by atrush            #+#    #+#             */
/*   Updated: 2017/01/10 15:04:54 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_d_i(va_list args, int frmt[9])
{
	char	*str;
	int		tmp;

	str = NULL;
	if (frmt[2] == 0)
		str = ft_itoa_ll(va_arg(args, int), 10);
	else if (frmt[2] == 1)
		str = ft_itoa_ll((signed char)va_arg(args, int), 10);
	else if (frmt[2] == 2)
		str = ft_itoa_ll((short int)va_arg(args, int), 10);
	else if (frmt[2] == 3)
		str = ft_itoa_ll(va_arg(args, long int), 10);
	else if (frmt[2] == 4)
		str = ft_itoa_ll(va_arg(args, long long int), 10);
	else if (frmt[2] == 5)
		str = ft_itoa_ll(va_arg(args, intmax_t), 10);
	else if (frmt[2] == 6)
		str = ft_itoa_size_t(va_arg(args, size_t), 10);
	if (!str)
		return (-1);
	frmt[7] = (*str == '-') ? 2 : frmt[7];
	*str = (frmt[1] == 0 && *str == '0') ? '\0' : *str;
	tmp = print(str, frmt, ft_strlen(str));
	free(str);
	return (tmp);
}

void		check_for_type_u_o_x(char **str, int frmt[9])
{
	if (frmt[3] == 10)
		ft_toupper(str);
	if ((frmt[3] > 8 || (frmt[3] == 7 && frmt[1] != 0)) && **str == '0')
		frmt[4] = 0;
	if (frmt[1] == 0 && **str == '0')
		**str = '\0';
}

static int	type_u_o_x(va_list args, int frmt[9], int base)
{
	char	*str;
	int		tmp;

	str = NULL;
	if (frmt[2] == 0)
		str = ft_itoa_u(va_arg(args, unsigned int), base);
	else if (frmt[2] == 1)
		str = ft_itoa_u((unsigned char)va_arg(args, unsigned int), base);
	else if (frmt[2] == 2)
		str = ft_itoa_u((unsigned short int)va_arg(args, unsigned int), base);
	else if (frmt[2] == 3)
		str = ft_itoa_u(va_arg(args, unsigned long int), base);
	else if (frmt[2] == 4)
		str = ft_itoa_u(va_arg(args, unsigned long long int), base);
	else if (frmt[2] == 5)
		str = ft_itoa_u(va_arg(args, uintmax_t), base);
	else if (frmt[2] == 6)
		str = ft_itoa_size_t(va_arg(args, size_t), base);
	if (!str)
		return (-1);
	check_for_type_u_o_x(&str, frmt);
	tmp = print(str, frmt, ft_strlen(str));
	free(str);
	return (tmp);
}

static int	check_int(char c, va_list args, int frmt[9])
{
	int base;

	if (c == 'D' || c == 'O' || c == 'U')
	{
		c += 32;
		frmt[2] = 3;
	}
	frmt[3] = (c == 'd' || c == 'i') ? 6 : frmt[3];
	frmt[3] = (c == 'o') ? 7 : frmt[3];
	frmt[3] = (c == 'u') ? 8 : frmt[3];
	frmt[3] = (c == 'x') ? 9 : frmt[3];
	frmt[3] = (c == 'X') ? 10 : frmt[3];
	if (!frmt[3])
		return (0);
	base = (frmt[3] == 7) ? 8 : 16;
	base = (frmt[3] == 8) ? 10 : base;
	if (frmt[3] == 6)
		return (type_d_i(args, frmt));
	else
		return (type_u_o_x(args, frmt, base));
}

int			check_type(const char *restrict str,
			int *i, va_list args, int frmt[9])
{
	if (str[*i] == 'S' || (str[*i] == 's' && frmt[2] == 3))
		return (type_ls(args, frmt, 0));
	else if (str[*i] == 's')
		return (type_s(args, frmt));
	else if (str[*i] == 'p')
		return (type_p(args, frmt));
	else if (str[*i] == 'C' || (str[*i] == 'c' && frmt[2] == 3))
		return (type_lc(args, frmt));
	else if (str[*i] == 'c' || str[*i] == '%')
		return (type_c(args, frmt, (str[*i] == '%') ? 1 : 0));
	return (check_int(str[*i], args, frmt));
}
