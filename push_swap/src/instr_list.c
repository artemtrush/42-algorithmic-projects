/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:29:07 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:15 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_instr(t_instr *com, int fd)
{
	while (com)
	{
		write(fd, com->action, ft_strlen(com->action));
		write(fd, "\n", 1);
		com = com->next;
	}
}

static void		remove_both(t_instr **com, unsigned int count)
{
	t_instr	*tmp1;
	t_instr	*tmp2;
	t_instr	*list;

	if (count == 0)
	{
		tmp1 = *com;
		tmp2 = tmp1->next;
		*com = tmp2->next;
	}
	else
	{
		list = *com;
		while (--count > 0)
			list = list->next;
		tmp1 = list->next;
		tmp2 = tmp1->next;
		list->next = tmp2->next;
	}
	free(tmp1);
	free(tmp2);
}

void			remove_unnecessary(t_instr **com)
{
	t_instr			*tmp;
	unsigned int	count;

	tmp = *com;
	count = 0;
	while (tmp && tmp->next)
		if (ft_ne_norma(tmp))
		{
			remove_both(com, count);
			tmp = *com;
			count = 0;
		}
		else
		{
			tmp = tmp->next;
			count++;
		}
}

void			delete_instr(t_instr **com)
{
	t_instr *tmp;

	tmp = *com;
	while (*com != NULL)
	{
		tmp = (*com)->next;
		free(*com);
		*com = tmp;
	}
}

int				new_com(t_instr **com, char *str)
{
	t_instr		*tmp;
	int			i;

	i = -1;
	tmp = *com;
	if (!tmp)
	{
		if (!(tmp = (t_instr*)malloc(sizeof(t_instr))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_instr*)malloc(sizeof(t_instr))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	while (str[++i])
		(tmp->action)[i] = str[i];
	(tmp->action)[i] = '\0';
	if (!(*com))
		*com = tmp;
	return (1);
}
