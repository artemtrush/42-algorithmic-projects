/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pls_do_not_open.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:30:30 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:30:34 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		decrease(t_list **stack, int num)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->num -= (tmp->num > num) ? 1 : 0;
		tmp = tmp->next;
	}
}

static void		minimization(t_list **stack, t_list **other_stack, int flag)
{
	t_list		*list;
	t_list		*tmp;

	list = *stack;
	while (list && list->next)
	{
		tmp = list->next;
		if (list->num == tmp->num + flag)
		{
			list->size += tmp->size;
			list->next = tmp->next;
			free(tmp);
			list->num -= (flag == 1) ? 1 : 0;
			decrease(stack, list->num);
			decrease(other_stack, list->num);
		}
		else
			list = list->next;
	}
}

static void		first_minimization(t_list **stack,
		long long count, long long value)
{
	t_list		*list;
	t_list		*tmp;

	list = *stack;
	while (list && (list = *stack))
	{
		value = find_first_min(*stack);
		while (list)
			if (list->num == value && list->size == 0)
			{
				list->num = count++;
				list->size = 1;
				tmp = list;
				while ((tmp = list->next) && tmp->size == 0
						&& tmp->num == find_first_min(*stack))
				{
					list->size += 1;
					list->next = tmp->next;
					free(tmp);
				}
				break ;
			}
			else
				list = list->next;
	}
}

void			old_terrible_algo(t_list **stack_a, t_list **stack_b,
				int flag, int fd)
{
	t_instr	*com;

	com = NULL;
	first_minimization(stack_a, 1, 0);
	while (!check(*stack_a, *stack_b))
	{
		magic(stack_a, stack_b, &com);
		minimization(stack_a, stack_b, -1);
		minimization(stack_b, stack_a, 1);
	}
	delete_list(stack_a);
	remove_unnecessary(&com);
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
