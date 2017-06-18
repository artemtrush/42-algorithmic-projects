/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:24:56 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 15:34:21 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean(t_list **stack_a, t_list **stack_b, int fd)
{
	delete_list(stack_a);
	delete_list(stack_b);
	*stack_a = NULL;
	*stack_a = NULL;
	if (fd != 0)
		close(fd);
}

static void	search_flags(char **argv, int *fd, int *flag, int argc)
{
	int i;
	int	print;
	int color;

	print = 0;
	color = 0;
	*flag = 0;
	*fd = 0;
	i = 0;
	while (++i < argc)
		if (ft_strcmp("-v", argv[i]))
			print = 1;
		else if (ft_strcmp("-c", argv[i]))
			color = 1;
		else if (ft_strcmp("-f", argv[i]) && *fd == 0)
		{
			if (i + 1 == argc || (*fd = open(argv[i + 1], O_RDWR)) == -1)
			{
				write(2, "No such file or directory\n", 26);
				exit(1);
			}
		}
	(color && print) ? *flag = 3 : *flag;
	(color && !print) ? *flag = 2 : *flag;
	(!color && print) ? *flag = 1 : *flag;
}

int			main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		fd;
	int		flag;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	search_flags(argv, &fd, &flag, argc);
	if ((stack_a = create_list(argc, argv, 0)))
	{
		if ((exec_commands(&stack_a, &stack_b, flag, fd)))
		{
			if (flag == 2 || flag == 3)
				check(stack_a, stack_b) ? ft_putstr(GREEN) : ft_putstr(RED);
			(check(stack_a, stack_b)) ? ft_putstr("OK\n") : ft_putstr("KO\n");
			if (flag == 2 || flag == 3)
				ft_putstr(RESET);
			clean(&stack_a, &stack_b, fd);
			return (0);
		}
		clean(&stack_a, &stack_b, fd);
	}
	write(2, "Error\n", 6);
	return (0);
}
