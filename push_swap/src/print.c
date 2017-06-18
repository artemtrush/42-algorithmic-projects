/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:30:46 by atrush            #+#    #+#             */
/*   Updated: 2017/03/01 14:30:49 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		return ;
	}
	else if ((n / 10) != 0)
		ft_putnbr(n / 10);
	ft_putchar(n - ((n / 10) * 10) + 48);
}

static void		print_num(int num)
{
	int tmp;
	int size;

	tmp = num;
	size = 0;
	if (tmp <= 0)
		size++;
	while (tmp != 0)
	{
		size++;
		tmp = tmp / 10;
	}
	size = 11 - size;
	tmp = -1;
	if (size % 2 != 0)
		write(1, " ", 1);
	if (size % 2 != 0)
		size--;
	while (++tmp < size / 2)
		write(1, " ", 1);
	ft_putnbr(num);
	while (tmp++ < size)
		write(1, " ", 1);
}

static void		print_elems(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 3)
		ft_putstr(BLACK);
	ft_putchar('|');
	if (flag == 3)
		ft_putstr(YELLOW);
	if (*stack_a)
		print_num((int)(*stack_a)->num);
	else
		ft_putstr("           ");
	if (*stack_a)
		*stack_a = (*stack_a)->next;
	if (flag == 3)
		ft_putstr(BLACK);
	ft_putstr("||");
	if (flag == 3)
		ft_putstr(BLUE);
	if (*stack_b)
		print_num((int)(*stack_b)->num);
	else
		ft_putstr("           ");
	if (*stack_b)
		*stack_b = (*stack_b)->next;
	if (flag == 3)
		ft_putstr(BLACK);
	ft_putstr("|\n");
}

void			print_stacks(t_list *stack_a, t_list *stack_b,
				int flag, char *str)
{
	if (!str)
		return ;
	if (flag == 3)
		ft_putstr(RED);
	ft_putstr(str);
	ft_putchar('\n');
	if (flag == 3)
		ft_putstr(BLACK);
	ft_putstr("|-----------||-----------|\n");
	ft_putstr("|  stack a  ||  stack b  |\n");
	ft_putstr("|-----------||-----------|\n");
	while (stack_a || stack_b)
		print_elems(&stack_a, &stack_b, flag);
	if (flag == 3)
		ft_putstr(BLACK);
	ft_putstr("|-----------||-----------|\n\n");
	if (flag == 3)
		ft_putstr(RESET);
	sleep(3);
}
