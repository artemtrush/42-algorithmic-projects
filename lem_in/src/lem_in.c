/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:56:01 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:56:05 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		leftcmp(t_ways **ways, int id, t_road *road, const char *room)
{
	t_ways *tmp;
	t_road *list;
	t_road *cur;

	tmp = *ways;
	while (tmp->id != id)
		tmp = tmp->next;
	list = tmp->road;
	while (ft_strcmp(list->room, room) != 0)
		list = list->next;
	list = list->next;
	while (list->next)
	{
		cur = road->next;
		while (cur->next)
		{
			if (ft_strcmp(list->room, cur->room) == 0)
				return (1);
			cur = cur->next;
		}
		list = list->next;
	}
	return (0);
}

static int		roadcmp(t_ways **ways, const char *room, int id, int diff)
{
	t_road *road;
	t_ways *tmp;

	tmp = *ways;
	while (tmp)
	{
		if (tmp->id != 0 && tmp->id != id)
		{
			road = tmp->road;
			while (road && road->next)
			{
				if (ft_strcmp(road->room, room) == 0)
					if (leftcmp(ways, id, road, room))
					{
						if (tmp->diff_lvl < diff)
							return (0);
						tmp->id = 0;
						break ;
					}
				road = road->next;
			}
		}
		tmp = tmp->next;
	}
	return (id);
}

static void		find_unnecessary(t_ways **ways, int range)
{
	t_ways	*tmp;
	int		successful_checks;
	t_road	*road;
	int		i;

	successful_checks = 1;
	while (successful_checks > 0)
	{
		tmp = *ways;
		successful_checks = 0;
		while (tmp)
		{
			if (tmp->id != 0 && range < tmp->diff_lvl)
			{
				i = 0;
				road = tmp->road;
				while (++i < range)
					road = road->next;
				tmp->id = roadcmp(ways, road->room, tmp->id, tmp->diff_lvl);
				successful_checks++;
			}
			tmp = tmp->next;
		}
		range++;
	}
}

static void		set_difficult(t_ways **ways)
{
	t_ways	*tmp;
	t_road	*list;
	int		count;
	int		id;

	id = 1;
	tmp = *ways;
	while (tmp)
	{
		list = tmp->road;
		count = 0;
		while (list)
		{
			count++;
			list = list->next;
		}
		tmp->diff_lvl = count;
		tmp->id = id;
		tmp = tmp->next;
		id++;
	}
}

int				main(void)
{
	t_ways	*ways;
	int		ant;

	ways = NULL;
	if (!reading(&ways, &ant) || !ways)
	{
		ft_printf("%sERROR\n%s", RED, RESET);
		return (0);
	}
	set_difficult(&ways);
	find_unnecessary(&ways, 2);
	delete_unnecessary(&ways);
	if (ant == 1)
		run_ant_run(&ways);
	else
		remove_crossroads(&ways);
	road_to_the_hellend(&ways, ant);
	delete_ways(&ways);
	return (0);
}
