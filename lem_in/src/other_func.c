/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:28:08 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 15:28:11 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			start(t_road **road, t_room *room)
{
	while (room)
	{
		if (room->start_or_end == -1)
		{
			if (!create_road(road, room->room))
				return (0);
			return (1);
		}
		room = room->next;
	}
	return (0);
}

int			print_text(t_text **text, t_room **room, char **line)
{
	t_ways *empty;
	t_text *tmp;

	empty = NULL;
	tmp = *text;
	while (tmp)
	{
		ft_printf("%s\n", tmp->text);
		tmp = tmp->next;
	}
	delete_all(text, &empty, room, line);
	return (1);
}

void		print_step(int *already_printed, int ant, const char *str)
{
	if (*already_printed)
		ft_printf(" ");
	else
		*already_printed = 1;
	ft_printf("L%d-%s", ant, str);
}

int			this_have_not_happened_before(t_road *road, const char *room)
{
	t_road *tmp;

	tmp = road;
	while (tmp)
	{
		if (ft_strcmp(tmp->room, room) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		swap_room_nodes(t_room **root, int node)
{
	t_room *tmp1;
	t_room *tmp2;

	tmp1 = *root;
	while (--node > 0)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	if (node == -1)
	{
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*root = tmp2;
	}
	else
	{
		tmp1->next = tmp2->next;
		tmp1 = tmp1->next;
		tmp2->next = tmp1->next;
		tmp1->next = tmp2;
	}
}
