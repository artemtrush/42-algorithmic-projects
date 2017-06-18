/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:55:34 by atrush            #+#    #+#             */
/*   Updated: 2017/02/11 11:55:38 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_other(char *buf, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(buf, "sa"))
		exec_sa_sb(stack_a);
	else if (ft_strcmp(buf, "sb"))
		exec_sa_sb(stack_b);
	else if (ft_strcmp(buf, "ss"))
	{
		exec_sa_sb(stack_a);
		exec_sa_sb(stack_b);
	}
	else if (ft_strcmp(buf, "pa"))
		exec_pa_pb(stack_b, stack_a);
	else if (ft_strcmp(buf, "pb"))
		exec_pa_pb(stack_a, stack_b);
	else if (ft_strcmp(buf, "ra"))
		exec_ra_rb(stack_a);
	else if (ft_strcmp(buf, "rb"))
		exec_ra_rb(stack_b);
	else if (ft_strcmp(buf, "rr"))
	{
		exec_ra_rb(stack_a);
		exec_ra_rb(stack_b);
	}
	else
		return (0);
	return (1);
}

int			valid_command(char *buf, t_list **stack_a, t_list **stack_b)
{
	if ((ft_strlen(buf) == 2))
		return (valid_other(buf, stack_a, stack_b));
	if (ft_strcmp(buf, "rra"))
		exec_rra_rrb(stack_a);
	else if (ft_strcmp(buf, "rrb"))
		exec_rra_rrb(stack_b);
	else if (ft_strcmp(buf, "rrr"))
	{
		exec_rra_rrb(stack_a);
		exec_rra_rrb(stack_b);
	}
	else
		return (0);
	return (1);
}

int			exec_commands(t_list **stack_a, t_list **stack_b, int flag, int fd)
{
	char	*line;

	line = NULL;
	if (flag == 1 || flag == 3)
		print_stacks(*stack_a, *stack_b, flag, line);
	while ((get_next_line(fd, &line)) == 1)
	{
		if (!line)
			return (0);
		if (ft_strlen(line) > 3 || ft_strlen(line) < 2)
		{
			free(line);
			return (0);
		}
		if (!(valid_command(line, stack_a, stack_b)))
		{
			free(line);
			return (0);
		}
		if (flag == 1 || flag == 3)
			print_stacks(*stack_a, *stack_b, flag, line);
		free(line);
		line = NULL;
	}
	return (1);
}

int			check(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || stack_b)
		return (0);
	if (!(stack_a->next))
		return (1);
	while (1)
	{
		if (stack_a->num > (stack_a->next)->num)
			return (0);
		stack_a = stack_a->next;
		if (!(stack_a->next))
			break ;
	}
	return (1);
}
