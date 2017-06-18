/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:27:38 by atrush            #+#    #+#             */
/*   Updated: 2017/01/21 18:37:50 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_int_prefix(int frmt[9], size_t size_precision)
{
	if (frmt[4] || frmt[3] == 3)
	{
		if (frmt[3] == 7)
			write(1, "0", 1);
		else if (frmt[3] == 9 || frmt[3] == 3)
			write(1, "0x", 2);
		else if (frmt[3] == 10)
			write(1, "0X", 2);
	}
	if (frmt[7] == 2)
		write(1, "-", 1);
	else if (frmt[7] == 1)
		write(1, "+", 1);
	else if (frmt[8])
		write(1, " ", 1);
	while (size_precision-- > 0)
		write(1, "0", 1);
}

static void		print_to_min_width(size_t width, int flag_0)
{
	while (width > 0)
	{
		if (flag_0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width--;
	}
}

static size_t	print_with_flags(void *str, int frmt[9],
	size_t size, size_t size_precision)
{
	size_t	size_after_fl;

	size_after_fl = (frmt[7] || frmt[8]) ? 1 : 0;
	size_after_fl += (frmt[4] && frmt[3] == 7) ? 1 : 0;
	size_after_fl += ((frmt[4] && frmt[3] != 7) || frmt[3] == 3) ? 2 : 0;
	size_precision = (size < (size_t)frmt[1]) ? (size_t)frmt[1] - size : 0;
	size_after_fl += size + size_precision;
	if (frmt[5])
		print_int_prefix(frmt, size_precision);
	if (size_after_fl < (size_t)frmt[0] && !frmt[6])
		print_to_min_width((size_t)(frmt[0] - size_after_fl), frmt[5]);
	if (!frmt[5])
		print_int_prefix(frmt, size_precision);
	str += (frmt[7] == 2) ? 1 : 0;
	if (!str)
		write(1, "(null)", size);
	else
		write(1, str, size);
	if (size_after_fl < (size_t)frmt[0] && frmt[6])
		print_to_min_width((size_t)(frmt[0] - size_after_fl), frmt[5]);
	if (!(frmt[3] = ((size_after_fl < (size_t)frmt[0]) ?
					frmt[0] : (int)size_after_fl)))
		return (-2);
	else
		return (frmt[3]);
}

int				print(void *str, int frmt[9], size_t size)
{
	if (frmt[3] < 6 || frmt[1] == -1)
		frmt[1] = 0;
	if (frmt[3] < 7)
		frmt[4] = 0;
	if ((frmt[3] < 6) || frmt[1] || frmt[6])
		frmt[5] = 0;
	if (frmt[3] != 6 || frmt[7])
		frmt[8] = 0;
	if (frmt[3] != 6)
		frmt[7] = 0;
	if (frmt[7] == 2)
		size--;
	return (print_with_flags(str, frmt, size, 0));
}
