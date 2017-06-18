/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:25:26 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 15:50:07 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		search_flags(char **argv, int *fd, int *flag, int argc)
{
	int i;

	*flag = 0;
	*fd = 1;
	i = 0;
	while (++i < argc)
		if (ft_strcmp("-c", argv[i]))
			*flag = 1;
		else if (ft_strcmp("-f", argv[i]) && *fd == 1)
		{
			if (i + 1 == argc)
				*fd = -1;
			else
			{
				*fd = creat(argv[i + 1], S_IREAD | S_IWRITE);
				if (*fd != -1 && *fd != 1)
					close(*fd);
				*fd = open(argv[i + 1], O_TRUNC | O_RDWR);
			}
			if (*fd == -1)
			{
				write(2, "No such file or directory\n", 26);
				exit(1);
			}
		}
}

int				main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		fd;
	int		flag;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	search_flags(argv, &fd, &flag, argc);
	if ((stack_a = create_list(argc, argv, 1)))
	{
		if (count_stack(stack_a) < 10)
			old_terrible_algo(&stack_a, &stack_b, flag, fd);
		else
			new_beautiful_algo(&stack_a, &stack_b, flag, fd);
	}
	else
		write(2, "Error\n", 6);
	if (fd != 1)
		close(fd);
	return (0);
}
