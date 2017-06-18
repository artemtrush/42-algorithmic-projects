/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:57:39 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:30:03 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			write_com(char *str, t_list **stack_a, t_list **stack_b,
				t_instr **com)
{
	if (!(new_com(com, str)))
	{
		delete_list(stack_a);
		delete_list(stack_b);
		delete_instr(com);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void			do_cmd(char *str, t_list **stack_a, t_list **stack_b,
				t_instr **com)
{
	int		tmp;
	t_list	*list;

	if (ft_strcmp(str, "pa") || ft_strcmp(str, "rb") || ft_strcmp(str, "sb"))
		tmp = (*stack_b)->size;
	else if (ft_strcmp(str, "pb") || ft_strcmp(str, "ra") ||
			ft_strcmp(str, "sa"))
		tmp = (*stack_a)->size;
	else
	{
		list = (ft_strcmp(str, "rra")) ? *stack_a : *stack_b;
		while (list->next)
			list = list->next;
		tmp = list->size;
	}
	valid_command(str, stack_a, stack_b);
	while (tmp-- > 0)
		write_com(str, stack_a, stack_b, com);
}

static int		ch_r(long long i, long long *elem,
		long long *distance, long long result)
{
	if (i == 1 && *elem == -1)
		*distance = -1;
	if ((result < *distance || *distance == -1) && result != -1)
	{
		*distance = result;
		*elem = i;
		return (1);
	}
	return (0);
}

static void		choose_way(t_list *st_a, t_list *st_b,
		int *t, long long *elem)
{
	long long	i;
	long long	s;
	long long	dst;

	i = 0;
	s = (find_max(st_a) < find_max(st_b)) ? find_max(st_b) : find_max(st_a);
	while (++i < s)
	{
		*t = (ch_r(i, elem, &dst, dst_swap(st_a, i, 0))) ? 10 : *t;
		*t = (ch_r(s - i, elem, &dst, dst_swap(st_b, s - i, 1))) ? 16 : *t;
		*t = (ch_r(s - i, elem, &dst, dst_throw_all(st_b, s - i, 1))) ? 15 : *t;
		*t = (ch_r(i, elem, &dst, dst_throw_all(st_a, i, 0))) ? 9 : *t;
		*t = (ch_r(i, elem, &dst, dst_just_up(st_a, st_b, i, 0))) ? 5 : *t;
		*t = (ch_r(s - i, elem, &dst,
					dst_just_up(st_b, st_a, s - i, 1))) ? 11 : *t;
		*t = (ch_r(i, elem, &dst, dst_just_down(st_a, i, 0))) ? 6 : *t;
		*t = (ch_r(s - i, elem, &dst, dst_just_down(st_b, s - i, 1))) ? 12 : *t;
		*t = (ch_r(i, elem, &dst, dst_up_down(st_b, st_a, i, 1))) ? 3 : *t;
		*t = (ch_r(i, elem, &dst, dst_up_down(st_a, st_b, i, 0))) ? 4 : *t;
		*t = (ch_r(i, elem, &dst, dst_two_up(st_a, st_b, i))) ? 1 : *t;
		*t = (ch_r(i, elem, &dst, dst_two_down(st_a, st_b, i))) ? 2 : *t;
	}
}

void			magic(t_list **stack_a, t_list **stack_b, t_instr **com)
{
	long long	elem;
	int			type;

	type = 0;
	elem = -1;
	if (count_stack(*stack_a) == 1 && count_stack(*stack_b) == 1)
		join_stacks(stack_a, stack_b, com);
	else
		choose_way(*stack_a, *stack_b, &type, &elem);
	(type == 1) ? two_up(stack_a, stack_b, elem, com) : (void)elem;
	(type == 2) ? two_down(stack_a, stack_b, elem, com) : (void)elem;
	(type == 3) ? up_down(stack_b, stack_a, elem, com) : (void)elem;
	(type == 4) ? up_down(stack_a, stack_b, -elem, com) : (void)elem;
	(type == 5) ? just_up(stack_a, stack_b, -elem, com) : (void)elem;
	(type == 6) ? just_down(stack_a, stack_b, -elem, com) : (void)elem;
	(type == 9) ? throw_all(stack_a, stack_b, -elem, com) : (void)elem;
	(type == 10) ? swap(stack_a, stack_b, -elem, com) : (void)elem;
	(type == 11) ? just_up(stack_b, stack_a, elem, com) : (void)elem;
	(type == 12) ? just_down(stack_b, stack_a, elem, com) : (void)elem;
	(type == 15) ? throw_all(stack_b, stack_a, elem, com) : (void)elem;
	(type == 16) ? swap(stack_b, stack_a, elem, com) : (void)elem;
}
