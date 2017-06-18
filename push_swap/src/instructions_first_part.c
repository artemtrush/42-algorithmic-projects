/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_first_part.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:56:33 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:30 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			two_up(t_list **st_a, t_list **st_b, long long elem,
				t_instr **com)
{
	join_implementation_rr(st_a, st_b, elem, com);
	if ((*st_a)->num == elem + 1)
		do_cmd("pa", st_a, st_b, com);
	else if (((*st_a)->size == 1) && ((*st_b)->size == 1))
	{
		do_cmd("pa", st_a, st_b, com);
		do_cmd("sa", st_a, st_b, com);
	}
	else if (count_stack(*st_a) == 1)
	{
		do_cmd("pa", st_a, st_b, com);
		((*st_a)->size < ((*st_a)->next)->size) ?
			do_cmd("ra", st_a, st_b, com) : do_cmd("rra", st_a, st_b, com);
	}
	else
	{
		do_cmd("ra", st_a, st_b, com);
		do_cmd("pa", st_a, st_b, com);
		(last(*st_a, 0) > find_max(*st_a) / 2) ?
			do_cmd("ra", st_a, st_b, com) : do_cmd("rra", st_a, st_b, com);
	}
}

void			two_down(t_list **st_a, t_list **st_b, long long elem,
			t_instr **com)
{
	join_implementation_rrr(st_a, st_b, elem, com);
	if ((*st_a)->num == elem + 1)
		do_cmd("pa", st_a, st_b, com);
	else if (count_stack(*st_a) == 1)
	{
		do_cmd("pa", st_a, st_b, com);
		if ((*st_a)->size < ((*st_a)->next)->size)
			do_cmd("ra", st_a, st_b, com);
		else
			do_cmd("rra", st_a, st_b, com);
	}
	else
	{
		do_cmd("pa", st_a, st_b, com);
		if (last(*st_a, 0) > find_max(*st_a) / 2)
			do_cmd("ra", st_a, st_b, com);
		else
			do_cmd("rra", st_a, st_b, com);
	}
}

void			up_down(t_list **st_1, t_list **st_2, long long elem,
				t_instr **c)
{
	int fg;

	fg = check_fg(&elem);
	while ((*st_1)->num != elem && (*st_1)->num != elem + 1)
		(fg) ? do_cmd("rb", st_2, st_1, c) : do_cmd("ra", st_1, st_2, c);
	while (last(*st_2, 0) != elem && last(*st_2, 0) != elem + 1)
		(fg) ? do_cmd("rra", st_2, st_1, c) : do_cmd("rrb", st_1, st_2, c);
	if ((!fg && (*st_1)->num == elem + 1) || (fg && (*st_1)->num == elem))
	{
		if (count_stack(*st_2) > 1)
			(fg) ? do_cmd("rra", st_2, st_1, c) : do_cmd("rrb", st_1, st_2, c);
		(fg) ? do_cmd("pa", st_2, st_1, c) : do_cmd("pb", st_1, st_2, c);
		return ;
	}
	(fg) ? do_cmd("pa", st_2, st_1, c) : do_cmd("pb", st_1, st_2, c);
	if (((!fg && (*st_2)->num < last(*st_2, 0)) ||
		(fg && (*st_2)->num > last(*st_2, 0))) && count_stack(*st_2) == 2)
	{
		if ((*st_2)->size < ((*st_2)->next)->size)
			(fg) ? do_cmd("ra", st_2, st_1, c) : do_cmd("rb", st_1, st_2, c);
		else
			(fg) ? do_cmd("rra", st_2, st_1, c) : do_cmd("rrb", st_1, st_2, c);
		return ;
	}
	up_down_end(st_1, st_2, fg, c);
}

static void		walk_to_elem(t_list **st_1, t_list **st_2, long long elem,
				t_instr **c)
{
	long long	dst1;
	long long	dst2;
	t_list		*list;
	int			fg;

	list = *st_1;
	dst1 = 0;
	dst2 = 0;
	fg = check_fg(&elem);
	while (list->num != elem && list->num != elem + 1)
	{
		dst1 += list->size;
		list = list->next;
	}
	while (list)
	{
		dst2 += list->size;
		list = list->next;
	}
	while (((*st_1)->num != elem || ((*st_1)->next)->num != elem + 1) &&
			((*st_1)->num != elem + 1 || ((*st_1)->next)->num != elem))
		if (dst1 < dst2)
			(fg) ? do_cmd("rb", st_2, st_1, c) : do_cmd("ra", st_1, st_2, c);
		else
			(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
}

void			swap(t_list **st_1, t_list **st_2, long long elem, t_instr **c)
{
	int fg;

	fg = check_fg(&elem);
	if (count_stack(*st_1) == 2)
	{
		swap_two_elems(st_1, st_2, fg, c);
		return ;
	}
	else if (((!fg && (*st_1)->num == elem + 1) || (fg && (*st_1)->num == elem))
			&& (last(*st_1, 0) == elem || last(*st_1, 0) == elem + 1))
	{
		if ((!fg && last(*st_1, 0) > find_max(*st_1) / 2) ||
				(fg && (*st_1)->num <= find_max(*st_1) / 2))
			(fg) ? do_cmd("rb", st_2, st_1, c) : do_cmd("ra", st_1, st_2, c);
		else
			(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
		return ;
	}
	else if (((*st_1)->num == elem || (*st_1)->num == elem + 1) &&
			(last(*st_1, 0) == elem || last(*st_1, 0) == elem + 1))
		(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
	else
		walk_to_elem(st_1, st_2, fg ? elem : -elem, c);
	(fg) ? do_cmd("sb", st_2, st_1, c) : do_cmd("sa", st_1, st_2, c);
}
