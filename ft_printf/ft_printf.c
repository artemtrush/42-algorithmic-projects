/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:32:17 by atrush            #+#    #+#             */
/*   Updated: 2017/01/21 18:37:30 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char *restrict format, int *i, va_list args)
{
	int	frmt[9];
	int k;

	k = 0;
	(*i)++;
	while (k < 9)
		frmt[k++] = 0;
	frmt[1] = -1;
	while (k > 0)
	{
		while ((k = check_flags(format, i, frmt)))
			;
		k += check_width(format, i, args, frmt);
		k += check_precision(format, i, args, frmt);
		k += check_size_modifier(format, i, frmt);
	}
	k = check_type(format, i, args, frmt);
	if (k > 0 || k == -2)
		(*i)++;
	if (k == -2)
		k = 0;
	return (k);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		i;
	int		count_print;
	int		tmp;

	i = 0;
	count_print = 0;
	va_start(args, format);
	while (format[i])
		if (format[i] == '%')
		{
			if ((tmp = check(format, &i, args)) == -1)
				count_print = -1;
			if (count_print == -1)
				break ;
			count_print += tmp;
		}
		else
		{
			count_print++;
			write(1, &(format[i++]), 1);
		}
	va_end(args);
	return (count_print);
}
