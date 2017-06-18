/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:00:40 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:31:16 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	find_avg(t_list *stack)
{
	long long	min;
	long long	max;
	int			size;

	size = stack->size;
	min = stack->num;
	max = stack->num;
	while (stack)
	{
		if (stack->size == size)
		{
			if (stack->num > max)
				max = stack->num;
			else if (stack->num < min)
				min = stack->num;
		}
		stack = stack->next;
	}
	return ((max + min) / 2);
}

int			yet_elems(t_list *stack, long long avg, int size)
{
	int count;

	count = 0;
	while (stack)
	{
		if (stack->size == size && stack->num <= avg)
			count++;
		stack = stack->next;
	}
	return (count);
}

long long	find_max(t_list *stack)
{
	long long max;

	if (!stack)
		return (0);
	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

long long	find_first_min(t_list *stack)
{
	long long min;

	while (stack && stack->size != 0)
		stack = stack->next;
	if (stack)
	{
		min = stack->num;
		while (stack)
		{
			if (stack->size == 0 && stack->num < min)
				min = stack->num;
			stack = stack->next;
		}
		return (min);
	}
	return (0);
}

int			count_stack(t_list *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
