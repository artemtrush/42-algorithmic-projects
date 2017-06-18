/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_second_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:56:06 by atrush            #+#    #+#             */
/*   Updated: 2017/02/11 11:56:14 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		dst_just_up(t_list *st_1, t_list *st_2, long long elem, int fg)
{
	long long	dst;
	t_list		*list;
	long long	tmp;

	if (!find_in_one_stack(st_1, elem))
		return (-1);
	dst = dst_to_elem(&st_1, elem);
	dst += st_1->size;
	list = st_1;
	st_1 = st_1->next;
	tmp = dst_to_elem(&st_1, elem);
	if ((!fg && list->num == elem) || (fg && list->num == elem + 1))
		dst += (!fg) ? (list->size + tmp) : (st_1->size + tmp);
	else if (count_stack(st_2) == 0)
		dst += (list->size < st_1->size) ? list->size + st_1->size + tmp
			: st_1->size * 2 + tmp;
	else
	{
		dst += st_1->size;
		dst += (tmp > list->size) ? tmp : list->size;
		dst += ((!fg && st_1->num <= find_max(st_2) / 2) ||
			(fg && list->num > find_max(st_2) / 2)) ? st_1->size : list->size;
	}
	return (dst);
}

long long		dst_just_down(t_list *st_1, long long elem, int fg)
{
	long long	dst;
	t_list		*list;
	long long	max;

	max = count_stack(st_1);
	if (!find_in_one_stack(st_1, elem))
		return (-1);
	dst_to_elem(&st_1, elem);
	list = st_1;
	st_1 = st_1->next;
	dst = dst_to_elem(&st_1, elem);
	dst += st_1->size * 3;
	if ((!fg && list->num == elem + 1) || (fg && list->num == elem))
		dst += list->size;
	else
	{
		if ((!fg && list->num > max / 2) || (fg && st_1->num <= max / 2))
			dst += st_1->size;
		else
			dst += list->size;
	}
	st_1 = st_1->next;
	dst += dst_to_elem(&st_1, elem);
	return (dst);
}

long long		dst_throw_all(t_list *stack, long long elem, int fg)
{
	long long	dst;
	long long	tmp;

	if (!find_in_one_stack(stack, elem))
		return (-1);
	dst = -1;
	if (((tmp = throw_up(stack, elem, fg)) < dst || dst == -1) && tmp != -1)
		dst = tmp;
	if (((tmp = throw_down(stack, elem, fg)) < dst || dst == -1) && tmp != -1)
		dst = tmp;
	if (((tmp = throw_edges(stack, elem, fg)) < dst || dst == -1) && tmp != -1)
		dst = tmp;
	return (dst);
}
