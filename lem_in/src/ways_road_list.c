/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_road_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:46:13 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:46:16 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		delete_all(t_text **text, t_ways **ways,
		t_room **room, char **line)
{
	if (*text)
		delete_text(text);
	if (*ways)
		delete_ways(ways);
	if (*room)
		delete_room(room);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (0);
}

int		delete_road(t_road **root)
{
	t_road *tmp;

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

int		delete_ways(t_ways **root)
{
	t_ways *tmp;

	tmp = *root;
	while (*root != NULL)
	{
		tmp = (*root)->next;
		delete_road(&((*root)->road));
		free(*root);
		*root = tmp;
	}
	return (0);
}

int		create_road(t_road **root, char *room)
{
	t_road *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_road*)malloc(sizeof(t_road))))
			return (0);
		tmp->prev = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_road*)malloc(sizeof(t_road))))
			return (0);
		(tmp->next)->prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->ant = 0;
	if (!(tmp->room = ft_strdup(room)))
		return (0);
	if (!(*root))
		*root = tmp;
	return (1);
}

int		create_ways(t_ways **root)
{
	t_ways *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_ways*)malloc(sizeof(t_ways))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_ways*)malloc(sizeof(t_ways))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->id = 0;
	tmp->diff_lvl = 0;
	tmp->road = NULL;
	if (!(*root))
		*root = tmp;
	return (1);
}
