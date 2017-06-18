/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_implementation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:57:13 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:50 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		join_stacks(t_list **stack_a, t_list **stack_b, t_instr **com)
{
	do_cmd("pa", stack_a, stack_b, com);
	if ((*stack_a)->num == 2)
	{
		if ((*stack_a)->size > ((*stack_a)->next)->size)
			do_cmd("rra", stack_a, stack_b, com);
		else
			do_cmd("ra", stack_a, stack_b, com);
	}
}

void		up_down_end(t_list **st_1, t_list **st_2, int fg, t_instr **com)
{
	if ((!fg && (*st_2)->num <= find_max(*st_2) / 2) ||
			(fg && (*st_2)->num > find_max(*st_2) / 2))
		(fg) ? do_cmd("ra", st_2, st_1, com) : do_cmd("rb", st_1, st_2, com);
	else
		(fg) ? do_cmd("rra", st_2, st_1, com) : do_cmd("rrb", st_1, st_2, com);
}

void		join_implementation_rr(t_list **st_a, t_list **st_b,
		long long elem, t_instr **com)
{
	long long	size_a;
	long long	size_b;

	size_a = 0;
	size_b = 0;
	while ((*st_a)->num != elem && (*st_a)->num != elem + 1)
	{
		size_a = size_a + (*st_a)->size;
		valid_command("ra", st_a, st_b);
	}
	while ((*st_b)->num != elem && (*st_b)->num != elem + 1)
	{
		size_b = size_b + (*st_b)->size;
		valid_command("rb", st_a, st_b);
	}
	while (size_a > 0 && size_b > 0)
	{
		write_com("rr", st_a, st_b, com);
		size_a--;
		size_b--;
	}
	while (size_a-- > 0)
		write_com("ra", st_a, st_b, com);
	while (size_b-- > 0)
		write_com("rb", st_a, st_b, com);
}

void		join_implementation_rrr(t_list **st_a, t_list **st_b,
		long long elem, t_instr **com)
{
	long long	size_a;
	long long	size_b;

	size_a = 1;
	size_b = 1;
	while (last(*st_a, 0) != elem && last(*st_a, 0) != elem + 1)
	{
		size_a = size_a + last(*st_a, 1);
		valid_command("rra", st_a, st_b);
	}
	while ((*st_b)->num != elem && (*st_b)->num != elem + 1)
	{
		size_b = size_b + last(*st_b, 1);
		valid_command("rrb", st_a, st_b);
	}
	if (last(*st_a, 0) == elem + 1 && count_stack(*st_a) > 1)
		size_a = size_a + last(*st_a, 1);
	if (last(*st_a, 0) == elem + 1 && count_stack(*st_a) > 1)
		valid_command("rra", st_a, st_b);
	while ((size_a-- > -1 && size_b-- > -1) && size_a > 0 && size_b > 0)
		write_com("rrr", st_a, st_b, com);
	while (size_a-- > 0)
		write_com("rra", st_a, st_b, com);
	while (size_b-- > 0)
		write_com("rrb", st_a, st_b, com);
}
