/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pleasant_viewing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:30:17 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:30:23 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		first_minimization(t_list **stack)
{
	t_list		*list;
	long long	count;
	long long	value;

	count = 1;
	list = *stack;
	while (list)
	{
		list = *stack;
		value = find_first_min(*stack);
		while (list)
		{
			if (list->num == value && list->size == 0)
			{
				list->num = count++;
				list->size = 1;
				break ;
			}
			list = list->next;
		}
	}
}

void			do_wrt(char *str, t_list **stack_a, t_list **stack_b,
				t_instr **com)
{
	if (ft_strcmp(str, "pb"))
		(*stack_a)->num *= -1;
	else if (ft_strcmp(str, "pa"))
	{
		(*stack_b)->num *= -1;
		(*stack_b)->size = 2;
	}
	valid_command(str, stack_a, stack_b);
	if (!(new_com(com, str)))
	{
		delete_list(stack_a);
		delete_list(stack_b);
		delete_instr(com);
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void		split_swap(t_list **st_1, t_list **st_2, int fg,
					t_instr **com)
{
	if (*st_2 && (*st_2)->next && (*st_2)->num > ((*st_2)->next)->num)
		fg ? do_wrt("ss", st_1, st_2, com) : do_wrt("ss", st_2, st_1, com);
	else
		fg ? do_wrt("sa", st_1, st_2, com) : do_wrt("sb", st_2, st_1, com);
}

static void		split(t_list **st_1, t_list **st_2, int fg, t_instr **com)
{
	long long	avg;
	int			size;

	avg = find_avg(*st_1);
	size = (*st_1)->size;
	while (yet_elems(*st_1, avg, size))
	{
		if ((*st_1)->num <= avg)
			fg ? do_wrt("pb", st_1, st_2, com) : do_wrt("pa", st_2, st_1, com);
		else if (maybe_swap(*st_1, avg, size))
			split_swap(st_1, st_2, fg, com);
		else if (count_sizes(*st_2) == 1 && (*st_2)->num > find_avg(*st_2))
			fg ? do_wrt("rr", st_1, st_2, com) : do_wrt("rr", st_2, st_1, com);
		else
			fg ? do_wrt("ra", st_1, st_2, com) : do_wrt("rb", st_2, st_1, com);
		if (fg && a_sort(*st_1))
			break ;
	}
	if (count_sizes(*st_1) > 1)
		while (last(*st_1, 1) == size)
			fg ? do_wrt("rra", st_1, st_2, com) :
			do_wrt("rrb", st_2, st_1, com);
	if (fg)
		up_sizes(st_2);
}

void			new_beautiful_algo(t_list **stack_a, t_list **stack_b,
				int flag, int fd)
{
	t_instr	*com;

	com = NULL;
	first_minimization(stack_a);
	while (!check(*stack_a, *stack_b))
		if (a_sort(*stack_a))
		{
			align_sizes(stack_a);
			split(stack_b, stack_a, 0, &com);
		}
		else if (mb_just_swap(stack_a, stack_b, &com) == 0)
			split(stack_a, stack_b, 1, &com);
	remove_unnecessary(&com);
	delete_list(stack_a);
	if (flag == 0 || fd != 1)
		print_instr(com, fd);
	if (flag)
	{
		ft_putstr(AMOUNT);
		write(1, "Operation amount: ", 18);
		ft_putnbr(count_instr(com));
		ft_putstr(RESET_AT);
	}
	delete_instr(&com);
}
