/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:45:01 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:45:52 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		roomcmp(char *s1, char *s2, const char *line)
{
	int ret;

	if (ft_strncmp(s1, line, ft_strlen(s1)) == 0)
	{
		ret = ft_strlen(s1);
		if (ft_strncmp(s1, line, ret) == 0)
			if (line[ret] == '-')
				if (ft_strcmp(s2, line + ret + 1) == 0)
					return (ret);
		return (0);
	}
	ret = ft_strlen(s2);
	if (ft_strncmp(s2, line, ret) == 0)
		if (line[ret] == '-')
			if (ft_strcmp(s1, line + ret + 1) == 0)
				return (ret);
	return (0);
}

int				is_it_link(const char *line, t_room *tmp)
{
	t_room *first;

	first = NULL;
	while (tmp)
	{
		if (ft_strstr(line, tmp->room))
		{
			if (!first)
				first = tmp;
			else
				break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	return (roomcmp(first->room, tmp->room, line));
}

static int		check_readed_rooms(t_room *room, int start_end, t_text *text)
{
	int start;
	int end;

	if (start_end != 0)
		return (0);
	start = 0;
	end = 0;
	while (room)
	{
		if (room->start_or_end == 1)
			end++;
		else if (room->start_or_end == -1)
			start++;
		room = room->next;
	}
	if (start == 1 && end == 1)
		if (check_coords(text->next))
			return (1);
	return (0);
}

static int		valid_room(t_room **room, char *line, int start_end)
{
	char	*tmp;
	int		i;
	int		res;

	i = 0;
	tmp = NULL;
	if (!(tmp = ft_strnew(ft_strlen(line))))
		return (0);
	while (line[i] && line[i] != ' ')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i++] = '\0';
	res = create_room(room, tmp, start_end);
	free(tmp);
	tmp = NULL;
	if (res == 0)
		return (0);
	if (!check_line_for_int(&(line[i]), ' '))
		return (0);
	while (line[i] != ' ')
		i++;
	return ((!check_line_for_int(&(line[++i]), '\0')) ? 0 : 1);
}

int				read_rooms(t_text **text, t_room **room, char **line)
{
	int tmp;
	int start_end;

	start_end = 0;
	while (get_next_line(0, line) == 1)
	{
		if (!create_text(text, *line))
			return (0);
		if ((tmp = is_it_link(*line, *room)) == -1)
			return (0);
		if (tmp > 0)
			return (check_readed_rooms(*room, start_end, *text));
		if (ft_strcmp(*line, "##start") == 0)
			start_end = -1;
		else if (ft_strcmp(*line, "##end") == 0)
			start_end = 1;
		else if ((*line)[0] != '#')
		{
			if (!valid_room(room, *line, start_end))
				return (0);
			start_end = 0;
		}
	}
	return (0);
}
