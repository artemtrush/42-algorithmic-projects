/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:31:22 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:47:11 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_ne_norma(t_instr *tmp)
{
	if ((ft_strcmp(tmp->action, "ra")
		&& ft_strcmp((tmp->next)->action, "rra")) ||
		(ft_strcmp(tmp->action, "rra")
		&& ft_strcmp((tmp->next)->action, "ra")) ||
		(ft_strcmp(tmp->action, "rb")
		&& ft_strcmp((tmp->next)->action, "rrb")) ||
		(ft_strcmp(tmp->action, "rrb")
		&& ft_strcmp((tmp->next)->action, "rb")) ||
		(ft_strcmp(tmp->action, "pa")
		&& ft_strcmp((tmp->next)->action, "pb")) ||
		(ft_strcmp(tmp->action, "pb")
		&& ft_strcmp((tmp->next)->action, "pa")))
		return (1);
	return (0);
}

int				count_instr(t_instr *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int				count_sizes(t_list *stack)
{
	int count;
	int	size;

	count = 0;
	while (stack)
	{
		size = stack->size;
		count++;
		while (stack && stack->size == size)
			stack = stack->next;
	}
	return (count);
}

void			up_sizes(t_list **stack)
{
	int		size;
	int		count;
	t_list	*list;

	count = 3;
	list = *stack;
	while (list)
	{
		size = list->size;
		while (list && list->size == size)
		{
			list->size = count;
			list = list->next;
		}
		count++;
	}
}

void			align_sizes(t_list **stack)
{
	t_list	*list;

	list = *stack;
	while (list)
	{
		list->size = 1;
		list = list->next;
	}
}
