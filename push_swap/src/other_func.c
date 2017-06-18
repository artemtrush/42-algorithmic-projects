/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:36:30 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:30:10 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_putstr(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
	}
}

long long		last(t_list *stack, int fg)
{
	while (stack->next)
		stack = stack->next;
	if (fg == 0)
		return (stack->num);
	return ((long long)stack->size);
}

int				ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

long long		ft_atol(const char *nptr)
{
	long long flag;
	long long result;

	flag = -1;
	result = 0;
	if (*nptr == '-')
	{
		flag = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		result = result * 10 - (*nptr - '0');
		nptr++;
	}
	return (result * flag);
}
