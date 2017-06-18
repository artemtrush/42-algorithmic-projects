/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_first_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:55:53 by atrush            #+#    #+#             */
/*   Updated: 2017/02/11 11:55:58 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		dst_two_up(t_list *st_a, t_list *st_b, long long elem)
{
	long long	dst;
	long long	tmp;
	t_list		*list;

	if (!find_in_two_stacks(st_a, st_b, elem))
		return (-1);
	list = st_a;
	tmp = dst_to_elem(&st_a, elem);
	dst = dst_to_elem(&st_b, elem);
	if (dst < tmp)
		dst = tmp;
	if (st_a->num == elem)
	{
		if ((st_a->size == 1) && (st_b->size == 1))
			dst += 1;
		else if (count_stack(list) == 1)
			dst += (st_a->size < st_b->size) ? st_a->size : st_b->size;
		else if (st_a->num > find_max(list) / 2)
			dst += st_a->size + st_b->size;
		else
			dst += st_a->size * 2;
	}
	dst += st_b->size;
	return (dst);
}

long long		dst_two_down(t_list *st_a, t_list *st_b, long long elem)
{
	long long	dst;
	long long	tmp1;
	long long	tmp2;
	long long	max;

	if (!find_in_two_stacks(st_a, st_b, elem))
		return (-1);
	max = find_max(st_a);
	tmp1 = count_stack(st_a);
	tmp2 = count_stack(st_b);
	dst_to_elem(&st_a, elem);
	dst_to_elem(&st_b, elem);
	tmp1 = (st_a->num == elem + 1 && tmp1 > 1) ? st_a->size : -tmp1;
	tmp2 = (st_a->num == elem + 1 && tmp2 > 1) ? st_b->size : -tmp2;
	dst = (st_a->num == elem && -tmp2 > 1) ? st_b->size : 0;
	dst += (-tmp1 == 1 && st_a->size < st_b->size) ? st_a->size : 0;
	dst += (-tmp1 == 1 && st_b->size < st_a->size) ? st_b->size : 0;
	if (st_a->num == elem && -tmp1 > 1)
		dst += (st_a->num > max / 2) ? st_b->size : st_a->size;
	dst += st_b->size;
	st_a = st_a->next;
	st_b = st_b->next;
	tmp1 = ((tmp1 < 0) ? 0 : tmp1) + dst_to_elem(&st_a, elem);
	tmp2 = ((tmp2 < 0) ? 0 : tmp2) + dst_to_elem(&st_b, elem);
	return ((tmp1 < tmp2) ? tmp2 + dst : tmp1 + dst);
}

long long		dst_up_down(t_list *st_1, t_list *st_2, long long elem, int fg)
{
	long long	dst;
	t_list		*tmp;

	if (!find_in_two_stacks(st_1, st_2, elem))
		return (-1);
	dst = 0;
	tmp = st_2;
	dst += dst_to_elem(&st_1, elem);
	dst += st_1->size;
	dst_to_elem(&st_2, elem);
	if ((!fg && st_1->num == elem) || (fg && st_1->num == elem + 1))
	{
		if (count_stack(tmp) == 1)
			dst += (st_1->size < st_2->size) ? st_1->size : st_2->size;
		else if ((!fg && st_1->num <= find_max(tmp) / 2) ||
				(fg && st_1->num > find_max(tmp) / 2))
			dst += st_1->size;
		else
			dst += st_2->size;
	}
	else if (count_stack(tmp) > 1)
		dst += st_2->size;
	st_2 = st_2->next;
	dst += dst_to_elem(&st_2, elem);
	return (dst);
}

long long		swap_edges(t_list *stack, long long elem, int fg, t_list *list)
{
	if ((!fg && stack->num == elem + 1) || (fg && stack->num == elem))
	{
		if ((!fg && list->num > find_max(stack) / 2) ||
				(fg && stack->num <= find_max(stack) / 2))
			return (stack->size);
		else
			return (list->size);
	}
	else if (stack->size == 1 && list->size == 1)
		return (2);
	return (-1);
}

long long		dst_swap(t_list *stack, long long elem, int fg)
{
	long long	dst;
	long long	tmp;
	t_list		*list;

	if (!find_in_one_stack(stack, elem))
		return (-1);
	list = stack;
	while (list->next)
		list = list->next;
	if (count_stack(stack) == 2)
		return ((stack->size < list->size) ? stack->size : list->size);
	if ((stack->num == elem || stack->num == elem + 1) &&
			(list->num == elem || list->num == elem + 1))
		return (swap_edges(stack, elem, fg, list));
	tmp = dst_to_elem(&stack, elem);
	if ((!fg && (stack->num != elem + 1 || (stack->next)->num != elem)) ||
			(fg && (stack->num != elem || (stack->next)->num != elem + 1)))
		return (-1);
	if (stack->size != 1 || (stack->next)->size != 1)
		return (-1);
	stack = (stack->next)->next;
	dst = dst_to_elem(&stack, elem) + 2;
	return ((dst < tmp) ? dst + 1 : tmp + 1);
}
