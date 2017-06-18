/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:48:25 by atrush            #+#    #+#             */
/*   Updated: 2017/01/10 15:04:31 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_size_modifier(const char *restrict str, int *i, int frmt[9])
{
	if (!str[*i])
		return (0);
	if (frmt[2])
	{
		if ((str[*i] == 'h' && str[*i + 1] == 'h') ||
			(str[*i] == 'l' && str[*i + 1] == 'l'))
			*i = *i + 2;
		else if ((str[*i] == 'l' || str[*i] == 'h' ||
		str[*i] == 'j' || str[*i] == 'z'))
			*i = *i + 1;
		else
			return (0);
		return (1);
	}
	frmt[2] = (str[*i] == 'h' && str[*i + 1] == 'h') ? 1 : frmt[2];
	frmt[2] = (str[*i] == 'h' && str[*i + 1] != 'h') ? 2 : frmt[2];
	frmt[2] = (str[*i] == 'l' && str[*i + 1] != 'l') ? 3 : frmt[2];
	frmt[2] = (str[*i] == 'l' && str[*i + 1] == 'l') ? 4 : frmt[2];
	frmt[2] = (str[*i] == 'j') ? 5 : frmt[2];
	frmt[2] = (str[*i] == 'z') ? 6 : frmt[2];
	if (!frmt[2])
		return (0);
	*i += (frmt[2] == 1 || frmt[2] == 4) ? 2 : 1;
	return (1);
}

int	check_precision(const char *restrict str, int *i,
	va_list args, int frmt[9])
{
	if (!str[*i])
		return (0);
	if (str[*i] == '.')
	{
		if (str[++(*i)] == '*')
		{
			frmt[1] = va_arg(args, int);
			(*i)++;
		}
		else
		{
			frmt[1] = ft_atoi(str + *i);
			while ((str[*i] > 47 && str[*i] < 58) && str[*i])
				(*i)++;
		}
	}
	else
		return (0);
	if (frmt[1] < -1)
		frmt[1] = -1;
	return (1);
}

int	check_width(const char *restrict str, int *i, va_list args, int frmt[9])
{
	if (!str[*i])
		return (0);
	if (str[*i] > 47 && str[*i] < 58)
	{
		frmt[0] = ft_atoi(str + *i);
		while ((str[*i] > 47 && str[*i] < 58) && str[*i])
			(*i)++;
	}
	else if (str[*i] == '*')
	{
		frmt[0] = va_arg(args, int);
		if (frmt[0] < 0)
		{
			frmt[0] = -frmt[0];
			frmt[6] = 1;
		}
		(*i)++;
	}
	else
		return (0);
	return (1);
}

int	check_flags(const char *restrict str, int *i, int frmt[9])
{
	if (!str[(*i)])
		return (0);
	if (str[(*i)] == '#' || str[(*i)] == '0' || str[(*i)] == '-' ||
		str[(*i)] == '+' || str[(*i)] == ' ')
	{
		frmt[4] = (str[(*i)] == '#' && !frmt[4]) ? 1 : frmt[4];
		frmt[5] = (str[(*i)] == '0' && !frmt[5]) ? 1 : frmt[5];
		frmt[6] = (str[(*i)] == '-' && !frmt[6]) ? 1 : frmt[6];
		frmt[7] = (str[(*i)] == '+' && !frmt[7]) ? 1 : frmt[7];
		frmt[8] = (str[(*i)] == ' ' && !frmt[8]) ? 1 : frmt[8];
		(*i)++;
		return (1);
	}
	return (0);
}
