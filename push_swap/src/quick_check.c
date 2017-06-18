/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:31:04 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:31:07 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		a_sort(t_list *stack_a)
{
	if (!stack_a)
		return (1);
	if (!(stack_a->next))
		return (1);
	while (stack_a->next)
	{
		if (stack_a->num + 1 != (stack_a->next)->num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int		maybe_swap(t_list *stack, long long avg, int size)
{
	int count;

	count = 0;
	if (!stack->next || (stack->next)->num > avg)
		return (0);
	while (stack)
	{
		if (stack->size == size && stack->num <= avg)
			count++;
		stack = stack->next;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		mb_just_swap(t_list **stack_a, t_list **stack_b, t_instr **com)
{
	t_list	*list;
	int		count;

	count = 0;
	list = *stack_a;
	while (list)
	{
		if (list->size == 2)
			count++;
		list = list->next;
	}
	if (count != 2)
		return (0);
	if ((*stack_a)->size != 2 || ((*stack_a)->next)->size != 2)
		return (0);
	if (*stack_b && (*stack_b)->next &&
		(*stack_b)->num > ((*stack_b)->next)->num)
		do_wrt("ss", stack_a, stack_b, com);
	else
		do_wrt("sa", stack_a, stack_b, com);
	return (1);
}
