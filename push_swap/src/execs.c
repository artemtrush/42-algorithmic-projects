/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:56:20 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:03 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_sa_sb(t_list **stack)
{
	int tmp;

	if (*stack)
	{
		if ((*stack)->next)
		{
			tmp = (*stack)->num;
			(*stack)->num = ((*stack)->next)->num;
			((*stack)->next)->num = tmp;
		}
	}
}

void		exec_pa_pb(t_list **stack_from, t_list **stack_on)
{
	t_list *tmp;

	if (*stack_from)
	{
		tmp = *stack_from;
		*stack_from = (*stack_from)->next;
		tmp->next = *stack_on;
		*stack_on = tmp;
	}
}

void		exec_ra_rb(t_list **stack)
{
	t_list *tmp;

	if (*stack)
	{
		if ((*stack)->next)
		{
			tmp = *stack;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			tmp = (*stack)->next;
			(*stack)->next = NULL;
			*stack = tmp;
		}
	}
}

void		exec_rra_rrb(t_list **stack)
{
	t_list *tmp;

	if (*stack)
	{
		if ((*stack)->next)
		{
			tmp = *stack;
			while ((tmp->next)->next)
				tmp = tmp->next;
			(tmp->next)->next = *stack;
			*stack = tmp->next;
			tmp->next = NULL;
		}
	}
}
