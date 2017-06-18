/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:27:53 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:59 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			delete_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (*list != NULL)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	return (0);
}

static int	create_elem(t_list **root, long long value)
{
	t_list *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_list*)malloc(sizeof(t_list))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_list*)malloc(sizeof(t_list))))
			return (delete_list(root));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->num = value;
	tmp->size = 0;
	if (!(*root))
		*root = tmp;
	return (1);
}

static int	add_elem(t_list **root, char *str)
{
	long long	tmp;
	t_list		*list;

	list = *root;
	if ((str[0] == '-' && (str[1] < 48 || str[1] > 57))
			|| (str[0] == 48 && str[1] != ' ' && str[1] != '\0'))
		return (delete_list(root));
	tmp = ft_atol(str);
	if (tmp < MIN_INT || tmp > MAX_INT)
		return (delete_list(root));
	while (list)
	{
		if (list->num == tmp)
			return (delete_list(root));
		list = list->next;
	}
	if (!create_elem(root, tmp))
		return (0);
	tmp = 0;
	if (str[tmp] == '-')
		tmp++;
	while (str[tmp] && str[tmp] > 47 && str[tmp] < 58)
		tmp++;
	return ((int)tmp);
}

static int	is_flag(int i, char **argv, int fg)
{
	if (ft_strcmp("-f", argv[i]))
		return (1);
	if (i > 1 && ft_strcmp("-f", argv[i - 1]))
		return (1);
	if (ft_strcmp("-c", argv[i]))
		return (1);
	if (fg == 0 && ft_strcmp("-v", argv[i]))
		return (1);
	return (0);
}

t_list		*create_list(int argc, char **argv, int fg)
{
	t_list		*root;
	int			i;
	int			k;
	int			tmp;

	root = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!is_flag(i, argv, fg) && (k = 0) >= 0)
		{
			while (argv[i][k])
				if ((argv[i][k] > 47 && argv[i][k] < 58) || argv[i][k] == '-')
				{
					if (!(tmp = add_elem(&root, &(argv[i][k]))))
						return (NULL);
					k += tmp;
				}
				else if (argv[i][k] == ' ')
					k++;
				else
					return (delete_list(&root) ? NULL : NULL);
		}
	}
	return (root);
}
