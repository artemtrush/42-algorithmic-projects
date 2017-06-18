/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:46:22 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:46:49 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_unnecessary(t_ways **ways)
{
	t_ways *tmp;
	t_ways *del;

	tmp = *ways;
	while (tmp && tmp->next)
	{
		if ((tmp->next)->id == 0)
		{
			del = tmp->next;
			tmp->next = del->next;
			delete_road(&(del->road));
			free(del);
		}
		else
			tmp = tmp->next;
	}
	if (*ways && (*ways)->id == 0)
	{
		del = *ways;
		*ways = del->next;
		delete_road(&(del->road));
		free(del);
	}
}

void	run_ant_run(t_ways **ways)
{
	t_ways	*tmp;
	int		id;

	tmp = *ways;
	id = find_min_way(tmp);
	while (tmp)
	{
		if (tmp->id != id)
			tmp->id = 0;
		tmp = tmp->next;
	}
	delete_unnecessary(ways);
}

void	remove_crossroads(t_ways **ways)
{
	int		max;
	t_ways	*tmp;
	t_ways	*max_road;
	int		res;

	while (1)
	{
		tmp = *ways;
		max = 0;
		while (tmp)
		{
			if (tmp->id != 0)
				if ((res = count_crossroads(*ways, tmp->id, 0)) > max)
				{
					max = res;
					max_road = tmp;
				}
			tmp = tmp->next;
		}
		if (max == 0)
			break ;
		max_road->id = 0;
	}
	delete_unnecessary(ways);
}

int		check_line_for_int(char *line, char c)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	if (line[0] == c)
		return (0);
	if (line[0] == '0' && line[1] != c)
		return (0);
	while (line[i] && line[i] != c)
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	if (line[i] != c)
		return (0);
	return (1);
}

int		check_coords(t_text *text)
{
	char	*str;
	char	*cmp;
	t_text	*tmp;

	while (text->next)
	{
		str = text->text;
		if (*str != '#')
		{
			while (*str && *str != ' ')
				str++;
			tmp = text->next;
			while (tmp->next)
			{
				cmp = tmp->text;
				while (*cmp && *cmp != ' ')
					cmp++;
				if (ft_strcmp(str + 1, cmp + 1) == 0)
					return (0);
				tmp = tmp->next;
			}
		}
		text = text->next;
	}
	return (1);
}
