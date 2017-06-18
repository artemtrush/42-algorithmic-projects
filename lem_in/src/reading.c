/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:45:45 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:45:48 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		add_way(t_ways **ways, t_road **road)
{
	t_ways *tmp;
	t_road *list;

	if (!create_ways(ways))
		return (delete_road(road));
	tmp = *ways;
	list = *road;
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (list)
	{
		if (!create_road(&(tmp->road), list->room))
			return (delete_road(road));
		if (!(list->next))
		{
			if (list->prev)
				(list->prev)->next = NULL;
			free(list->room);
			free(list);
			list = NULL;
			return (1);
		}
		list = list->next;
	}
	return (delete_road(road));
}

static int		happy_end(const char *name, t_room *room)
{
	while (room)
	{
		if (ft_strcmp(room->room, name) == 0)
		{
			if (room->start_or_end == 1)
				return (1);
			return (0);
		}
		room = room->next;
	}
	return (0);
}

static int		try_all(t_link *link, t_road **road,
				t_room *room, t_ways **ways)
{
	while (link)
	{
		if (this_have_not_happened_before(*road, link->room))
		{
			if (!create_road(road, link->room))
				return (delete_road(road));
			if (!build_walkways(ways, room))
				return (delete_road(road));
		}
		link = link->next;
	}
	return (1);
}

int				build_walkways(t_ways **ways, t_room *room)
{
	static t_road	*road;
	t_road			*tmp;
	t_room			*list;
	t_link			*link;

	if (!road)
		if (!start(&road, room))
			return (delete_road(&road));
	tmp = road;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (happy_end(tmp->room, room))
		return (add_way(ways, &road));
	list = room;
	while (list && ft_strcmp(list->room, tmp->room) != 0)
		list = list->next;
	if (!list)
		return (0);
	link = list->link;
	if (try_all(link, &road, room, ways) != 1)
		return (0);
	tmp_free(&tmp);
	return (1);
}

int				reading(t_ways **ways, int *ant)
{
	char	*line;
	t_text	*text;
	t_room	*room;

	line = NULL;
	text = NULL;
	room = NULL;
	get_next_line(0, &line);
	if (!line || !check_line_for_int(line, '\0'))
		return (delete_all(&text, ways, &room, &line));
	if ((*ant = ft_atoi(line)) == 0)
	{
		ft_printf("%sAnthill is empty :(\n%s", YELLOW, RESET);
		free(line);
		exit(1);
	}
	if (!create_text(&text, line))
		return (delete_all(&text, ways, &room, &line));
	if (!read_rooms(&text, &room, &line))
		return (delete_all(&text, ways, &room, &line));
	if (!read_links(&text, &room, &line))
		return (delete_all(&text, ways, &room, &line));
	if (!build_walkways(ways, room) || !ways)
		return (delete_all(&text, ways, &room, &line));
	return (print_text(&text, &room, &line));
}
