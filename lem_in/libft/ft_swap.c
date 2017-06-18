/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:28:56 by atrush            #+#    #+#             */
/*   Updated: 2016/12/09 12:50:49 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *x, void *y)
{
	unsigned char temp;
	unsigned char *a;
	unsigned char *b;

	if (x && y)
	{
		a = x;
		b = y;
		temp = *b;
		*b = *a;
		*a = temp;
	}
}
