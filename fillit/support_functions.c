/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:05:04 by atrush            #+#    #+#             */
/*   Updated: 2016/12/16 19:10:03 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqr(int num)
{
	int k;

	k = 1;
	while (k * k < num)
		k++;
	return (k);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
	}
}

void	definition_of_the_beginning(int k, int *w, int *h, int size)
{
	if (k == -1)
	{
		*w = 0;
		*h = 0;
	}
	else
	{
		*w = 1;
		while (k > 0 && k % (size + 1) != 0)
		{
			(*w)++;
			k--;
			*h = k / size;
		}
	}
}
