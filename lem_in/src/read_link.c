/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:44:36 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:44:39 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			tmp_free(t_road **tmp)
{
	if ((*tmp)->prev)
		((*tmp)->prev)->next = NULL;
	free((*tmp)->room);
	free((*tmp));
	*tmp = NULL;
}

int				delete_link(t_link **root)
{
	t_link *tmp;

	tmp = *root;
	while (*root != NULL)
	{
		tmp = (*root)->next;
		if ((*root)->room)
		{
			free((*root)->room);
			(*root)->room = NULL;
		}
		free(*root);
		*root = tmp;
	}
	return (0);
}

static int		create_link(t_link **root, char *name)
{
	t_link *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_link*)malloc(sizeof(t_link))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_link*)malloc(sizeof(t_link))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->room = ft_strdup(name);
	if (!(tmp->room))
		return (0);
	if (!(*root))
		*root = tmp;
	return (1);
}

static int		record_linkage(t_room **room, char *line, int pos)
{
	char	*tmp;
	t_room	*list;
	int		res;

	tmp = NULL;
	if (!(tmp = ft_strnew(pos)))
		return (0);
	tmp = ft_strncpy(tmp, line, pos);
	line = line + pos + 1;
	list = *room;
	while (list)
	{
		res = 1;
		if (ft_strcmp(list->room, tmp) == 0)
			res = create_link(&(list->link), line);
		else if (ft_strcmp(list->room, line) == 0)
			res = create_link(&(list->link), tmp);
		if (res == 0)
			free(tmp);
		if (res == 0)
			return (0);
		list = list->next;
	}
	free(tmp);
	return (1);
}

int				read_links(t_text **text, t_room **room, char **line)
{
	int pos;

	pos = is_it_link(*line, *room);
	if (!record_linkage(room, *line, pos))
		return (0);
	while ((pos = get_next_line(0, line)) == 1)
	{
		if ((*line)[0] == '#')
		{
			if (!create_text(text, *line))
				return (0);
		}
		else
		{
			if ((pos = is_it_link(*line, *room)) == -1)
				return (0);
			if (pos == 0)
				return (1);
			if (!create_text(text, *line))
				return (0);
			if (!record_linkage(room, *line, pos))
				return (0);
		}
	}
	return ((pos == 0) ? 1 : 0);
}
