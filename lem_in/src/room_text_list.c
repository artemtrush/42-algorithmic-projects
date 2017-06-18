/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_text_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:46:00 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 14:46:06 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				delete_text(t_text **root)
{
	t_text *tmp;

	while (*root)
	{
		tmp = *root;
		*root = tmp->next;
		if (tmp->text)
		{
			free(tmp->text);
			tmp->text = NULL;
		}
		free(tmp);
	}
	return (0);
}

int				create_text(t_text **root, char *text)
{
	t_text *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_text*)malloc(sizeof(t_text))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_text*)malloc(sizeof(t_text))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->text = ft_strdup(text);
	if (!(tmp->text))
		return (0);
	if (!(*root))
		*root = tmp;
	return (1);
}

int				delete_room(t_room **root)
{
	t_room *tmp;

	tmp = *root;
	while (*root != NULL)
	{
		tmp = (*root)->next;
		if ((*root)->room)
		{
			free((*root)->room);
			(*root)->room = NULL;
		}
		if ((*root)->link)
			delete_link(&((*root)->link));
		free(*root);
		*root = tmp;
	}
	return (0);
}

static void		sort_room(t_room **root)
{
	int		count;
	t_room	*tmp;
	int		node;

	count = 0;
	tmp = *root;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	while (--count > 0)
	{
		tmp = *root;
		node = 0;
		while (tmp && tmp->next)
		{
			if (ft_strlen(tmp->room) < ft_strlen((tmp->next)->room))
				swap_room_nodes(root, node);
			tmp = tmp->next;
			node++;
		}
	}
}

int				create_room(t_room **root, char *name, int start_end)
{
	t_room *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_room*)malloc(sizeof(t_room))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_room*)malloc(sizeof(t_room))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->link = NULL;
	tmp->start_or_end = start_end;
	if (!(tmp->room = ft_strdup(name)))
		return (0);
	if (!(*root))
		*root = tmp;
	sort_room(root);
	return (1);
}
