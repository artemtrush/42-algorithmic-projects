/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_before_dst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:55:03 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:28:15 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		dst_to_elem(t_list **stack, long long elem)
{
	long long dst;

	dst = 0;
	while (*stack && (*stack)->num != elem && (*stack)->num != elem + 1)
	{
		dst += (*stack)->size;
		*stack = (*stack)->next;
	}
	return (dst);
}

int				small_size(t_list *stack, long long elem)
{
	while (stack)
	{
		if (stack->num == elem || stack->num == elem + 1)
		{
			if (stack->size != 1)
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int				find_in_one_stack(t_list *stack, long long elem)
{
	int	found;

	found = 0;
	while (stack)
	{
		if (stack->num == elem || stack->num == elem + 1)
			found++;
		stack = stack->next;
	}
	if (found == 2)
		return (1);
	return (0);
}

int				find_in_two_stacks(t_list *st_1, t_list *st_2, long long elem)
{
	int	found;

	found = 0;
	while (st_1)
	{
		if (st_1->num == elem || st_1->num == elem + 1)
		{
			found = 1;
			break ;
		}
		st_1 = st_1->next;
	}
	while (found > 0 && st_2)
	{
		if (st_2->num == elem || st_2->num == elem + 1)
		{
			found = 2;
			break ;
		}
		st_2 = st_2->next;
	}
	if (found == 2)
		return (1);
	return (0);
}

void			swap_two_elems(t_list **st_1, t_list **st_2, int fg,
				t_instr **c)
{
	if ((*st_1)->size < ((*st_1)->next)->size)
		(fg) ? do_cmd("rb", st_2, st_1, c) : do_cmd("ra", st_1, st_2, c);
	else
		(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
}
