/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_second_part.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:56:50 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:41 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_fg(long long *elem)
{
	if (*elem < 0)
	{
		*elem *= -1;
		return (0);
	}
	return (1);
}

static void	join_rr_for_up(t_list **st_1, t_list **st_2, long long elem,
			t_instr **c)
{
	long long	size_1;
	long long	size_2;
	int			fg;

	fg = check_fg(&elem);
	size_1 = 0;
	size_2 = 0;
	while ((*st_1)->num != elem && (*st_1)->num != elem + 1)
	{
		size_1 = size_1 + (*st_1)->size;
		(!fg) ? valid_command("ra", st_1, st_2) :
			valid_command("rb", st_2, st_1);
	}
	size_2 = size_2 + (*st_2)->size;
	(!fg) ? valid_command("rb", st_1, st_2) : valid_command("ra", st_2, st_1);
	while (size_1 > 0 && size_2 > 0)
	{
		(!fg) ? write_com("rr", st_1, st_2, c) : write_com("rr", st_2, st_1, c);
		size_1--;
		size_2--;
	}
	while (size_1-- > 0)
		(!fg) ? write_com("ra", st_1, st_2, c) : write_com("rb", st_2, st_1, c);
	while (size_2-- > 0)
		(!fg) ? write_com("rb", st_1, st_2, c) : write_com("ra", st_2, st_1, c);
}

void		just_up(t_list **st_1, t_list **st_2, long long elem, t_instr **com)
{
	int fg;

	fg = check_fg(&elem);
	while ((*st_1)->num != elem && (*st_1)->num != elem + 1)
		(fg) ? do_cmd("rb", st_2, st_1, com) : do_cmd("ra", st_1, st_2, com);
	(fg) ? do_cmd("pa", st_2, st_1, com) : do_cmd("pb", st_1, st_2, com);
	if ((!fg && (*st_2)->num == elem + 1) || (fg && (*st_2)->num == elem))
	{
		join_rr_for_up(st_1, st_2, fg ? elem : -elem, com);
		(fg) ? do_cmd("pa", st_2, st_1, com) : do_cmd("pb", st_1, st_2, com);
		swap(st_2, st_1, fg ? -elem : elem, com);
		return ;
	}
	while ((*st_1)->num != elem && (*st_1)->num != elem + 1)
		(fg) ? do_cmd("rb", st_2, st_1, com) : do_cmd("ra", st_1, st_2, com);
	(fg) ? do_cmd("pa", st_2, st_1, com) : do_cmd("pa", st_1, st_2, com);
}

void		just_down(t_list **st_1, t_list **st_2, long long elem,
			t_instr **com)
{
	int fg;

	fg = check_fg(&elem);
	while (last(*st_1, 0) != elem && last(*st_1, 0) != elem + 1)
		(fg) ? do_cmd("rrb", st_2, st_1, com) : do_cmd("rra", st_1, st_2, com);
	(fg) ? do_cmd("rrb", st_2, st_1, com) : do_cmd("rra", st_1, st_2, com);
	(fg) ? do_cmd("pa", st_2, st_1, com) : do_cmd("pb", st_1, st_2, com);
	while (last(*st_1, 0) != elem && last(*st_1, 0) != elem + 1)
		(fg) ? do_cmd("rrb", st_2, st_1, com) : do_cmd("rra", st_1, st_2, com);
	if ((!fg && (*st_2)->num == elem) || (fg && (*st_2)->num == elem + 1))
	{
		(fg) ? do_cmd("rrb", st_2, st_1, com) : do_cmd("rra", st_1, st_2, com);
		(fg) ? do_cmd("pb", st_2, st_1, com) : do_cmd("pa", st_1, st_2, com);
		return ;
	}
	(fg) ? do_cmd("pb", st_2, st_1, com) : do_cmd("pa", st_1, st_2, com);
	swap(st_1, st_2, fg ? elem : -elem, com);
}

void		throw_all(t_list **st_1, t_list **st_2, long long elem,
			t_instr **c)
{
	int fg;

	fg = check_fg(&elem);
	if (dst_throw_all(*st_1, elem, fg) == throw_up(*st_1, elem, fg))
	{
		while ((*st_1)->num != elem && (*st_1)->num != elem + 1)
			(fg) ? do_cmd("rb", st_2, st_1, c) : do_cmd("ra", st_1, st_2, c);
		(fg) ? do_cmd("rb", st_2, st_1, c) : do_cmd("ra", st_1, st_2, c);
	}
	else if (dst_throw_all(*st_1, elem, fg) == throw_down(*st_1, elem, fg))
	{
		while (last(*st_1, 0) != elem && last(*st_1, 0) != elem + 1)
			(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
		(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
		while (last(*st_1, 0) != elem && last(*st_1, 0) != elem + 1)
			(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
	}
	else
		while (last(*st_1, 0) != elem && last(*st_1, 0) != elem + 1)
			(fg) ? do_cmd("rrb", st_2, st_1, c) : do_cmd("rra", st_1, st_2, c);
	while ((*st_1)->num != elem && (*st_1)->num != elem + 1)
		(fg) ? do_cmd("pa", st_2, st_1, c) : do_cmd("pb", st_1, st_2, c);
	swap(st_1, st_2, fg ? elem : -elem, c);
}
