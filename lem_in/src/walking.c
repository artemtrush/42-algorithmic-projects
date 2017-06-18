/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:47:52 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:47:55 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				find_min_way(t_ways *ways)
{
	t_ways *min;

	min = NULL;
	while (ways)
	{
		if (((ways->road)->next)->ant == 0)
			if (min == NULL || ways->diff_lvl < min->diff_lvl)
				min = ways;
		ways = ways->next;
	}
	if (min)
		return (min->id);
	return (0);
}

int				count_crossroads(t_ways *ways, int id, int crossroads)
{
	t_ways *tmp;
	t_road *curroad;
	t_road *road;

	tmp = ways;
	while (tmp->id != id)
		tmp = tmp->next;
	curroad = (tmp->road)->next;
	while (curroad && curroad->next)
	{
		tmp = ways;
		while (tmp)
		{
			if (tmp->id != id && tmp->id != 0 && (road = (tmp->road)->next))
				while (road && road->next)
				{
					if (ft_strcmp(curroad->room, road->room) == 0)
						crossroads++;
					road = road->next;
				}
			tmp = tmp->next;
		}
		curroad = curroad->next;
	}
	return (crossroads);
}

static int		ant_on_the_way(t_road **road, int *already_printed, t_road *tmp)
{
	t_road		*prev;
	t_road		*end;
	const char	*start_room;

	tmp = *road;
	start_room = tmp->room;
	while (tmp && tmp->next)
		tmp = tmp->next;
	end = tmp;
	while ((prev = tmp->prev))
	{
		if (ft_strcmp(prev->room, start_room) == 0)
			break ;
		if (tmp->ant == 0 && prev->ant != 0)
		{
			tmp->ant = prev->ant;
			prev->ant = 0;
			print_step(already_printed, tmp->ant, tmp->room);
		}
		tmp = tmp->prev;
	}
	if (end->ant == 0)
		return (0);
	end->ant = 0;
	return (1);
}

static int		go_out_on_a_mission(t_ways **ways,
		int *ant_number, int *already_printed)
{
	t_ways	*tmp;
	t_road	*road;
	int		id;

	tmp = *ways;
	id = find_min_way(*ways);
	while (tmp->id != id)
		tmp = tmp->next;
	road = (tmp->road)->next;
	road->ant = (*ant_number)++;
	if (*already_printed)
		ft_printf(" ");
	else
		*already_printed = 1;
	ft_printf("L%d-%s", road->ant, road->room);
	if (!(road->next))
	{
		road->ant = 0;
		return (1);
	}
	tmp->diff_lvl++;
	return (0);
}

void			road_to_the_hellend(t_ways **ways, int ant)
{
	int		come;
	int		already_printed;
	t_ways	*tmp;
	int		ant_number;

	ant_number = 1;
	come = ant;
	ft_printf("\n");
	while (come > 0)
	{
		tmp = *ways;
		already_printed = 0;
		while (tmp)
		{
			come -= ant_on_the_way(&(tmp->road), &already_printed, NULL);
			tmp = tmp->next;
		}
		while (ant && (find_min_way(*ways)))
		{
			come -= go_out_on_a_mission(ways, &ant_number, &already_printed);
			ant--;
		}
		ft_printf("\n");
	}
}
