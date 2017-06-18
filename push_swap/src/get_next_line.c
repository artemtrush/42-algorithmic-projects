/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:49:09 by atrush            #+#    #+#             */
/*   Updated: 2016/12/28 17:25:56 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_gnl	*create_node(int fd)
{
	t_gnl			*new;
	unsigned int	i;

	new = (t_gnl*)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	i = 0;
	while (i < BUFF_SIZE)
		new->buf[i++] = '\0';
	new->size = 0;
	new->next = NULL;
	return (new);
}

int		create_line(char **line, int line_size, int add_size)
{
	char	*tmp;
	int		i;

	if (line_size > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * line_size)))
			free((*line));
		if (!tmp)
			return (-1);
		i = -1;
		while (++i < line_size)
			tmp[i] = (*line)[i];
		free((*line));
		i = -1;
	}
	if ((*line = (char*)malloc(sizeof(char) * line_size + add_size + 1)))
	{
		i = -1;
		while (++i < line_size)
			(*line)[i] = tmp[i];
		(*line)[line_size + add_size] = '\0';
	}
	if (line_size > 0)
		free(tmp);
	return ((i != -1) ? (line_size + add_size) : (-1));
}

int		write_line(char **line, t_gnl *node, int i, int k)
{
	while (k < node->size)
	{
		if ((node->buf)[k] == '\n')
		{
			(node->buf)[k] = '\0';
			if ((create_line(line, i, 0)) == -1)
				return (0);
			return (-1);
		}
		(*line)[i++] = (node->buf)[k];
		(node->buf)[k++] = '\0';
	}
	return (i);
}

int		read_line(t_gnl *node, char **line, int i, int line_size)
{
	int	k;

	while (1)
	{
		k = -1;
		while (++k < node->size)
			if ((node->buf)[k] != '\0')
				break ;
		if (k == node->size)
		{
			k = 0;
			if ((node->size = read(node->fd, node->buf, BUFF_SIZE)) == -1)
				return (-1);
			if (node->size == 0)
				return ((i == 0) ? 0 : 1);
		}
		if (i >= line_size)
			if ((line_size =
				create_line(line, line_size, node->size - k)) == -1)
				return (-1);
		if ((i = write_line(line, node, i, k)) == 0)
			return (-1);
		if (i == -1)
			return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*root;
	t_gnl			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!root)
	{
		if (!(root = create_node(fd)))
			return (-1);
		return (read_line(root, line, 0, 0));
	}
	tmp = root;
	while (tmp->next)
		if (tmp->fd == fd)
			break ;
		else
			tmp = tmp->next;
	if (tmp->fd != fd)
	{
		if (!(tmp->next = create_node(fd)))
			return (-1);
		tmp = tmp->next;
	}
	return (read_line(tmp, line, 0, 0));
}
