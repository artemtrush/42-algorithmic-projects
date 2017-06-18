/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:00:51 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:31:32 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	throw_up(t_list *stack, long long elem, int fg)
{
	long long	dst;
	long long	max;
	t_list		*list;

	max = find_max(stack);
	dst = dst_to_elem(&stack, elem);
	if ((!fg && stack->num == elem + 1) || (fg && stack->num == elem))
	{
		if (small_size(stack, elem) == 0)
			return (-1);
		else
			dst++;
	}
	dst += stack->size;
	list = stack;
	stack = stack->next;
	dst += dst_to_elem(&stack, elem);
	if ((!fg && list->num > max / 2) || (fg && stack->num <= max / 2))
		dst += stack->size;
	else
		dst += list->size;
	return (dst);
}

long long	throw_down(t_list *stack, long long elem, int fg)
{
	long long	dst;
	long long	max;
	t_list		*list;

	dst = 0;
	max = find_max(stack);
	dst_to_elem(&stack, elem);
	if ((!fg && stack->num == elem + 1) || (fg && stack->num == elem))
	{
		if (small_size(stack, elem) == 0)
			return (-1);
		else
			dst++;
	}
	list = stack;
	stack = stack->next;
	dst += dst_to_elem(&stack, elem) * 2;
	dst += stack->size;
	if ((!fg && list->num > max / 2) || (fg && stack->num <= max / 2))
		dst += stack->size;
	else
		dst += list->size;
	stack = stack->next;
	dst += dst_to_elem(&stack, elem);
	return (dst);
}

long long	throw_edges(t_list *stack, long long elem, int fg)
{
	long long	dst;
	long long	max;
	t_list		*list;

	max = find_max(stack);
	dst = dst_to_elem(&stack, elem);
	if ((!fg && stack->num == elem) || (fg && stack->num == elem + 1))
	{
		if (small_size(stack, elem) == 0)
			return (-1);
		else
			dst++;
	}
	list = stack;
	stack = stack->next;
	dst_to_elem(&stack, elem);
	if ((!fg && stack->num > max / 2) || (fg && list->num <= max / 2))
		dst += list->size;
	else
		dst += stack->size;
	stack = stack->next;
	dst += dst_to_elem(&stack, elem) * 2;
	return (dst);
}
