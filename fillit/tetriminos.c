/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:51:11 by atrush            #+#    #+#             */
/*   Updated: 2016/12/15 17:48:26 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	*g_tetra;

void	tetra_create(int t, int n, int x, int y)
{
	g_tetra[t].x[n] = x;
	g_tetra[t].y[n] = y;
}

void	create_first_part(void)
{
	tetra_create(1, 0, 0, 0);
	tetra_create(1, 1, 1, 0);
	tetra_create(1, 2, 2, 0);
	tetra_create(1, 3, 0, 1);
	tetra_create(2, 0, 0, 0);
	tetra_create(2, 1, 1, 0);
	tetra_create(2, 2, 2, 0);
	tetra_create(2, 3, 1, 1);
	tetra_create(3, 0, 0, 0);
	tetra_create(3, 1, 1, 0);
	tetra_create(3, 2, 2, 0);
	tetra_create(3, 3, 2, 1);
	tetra_create(4, 0, 0, 0);
	tetra_create(4, 1, 1, 0);
	tetra_create(4, 2, 0, 1);
	tetra_create(4, 3, 1, 1);
	tetra_create(5, 0, 0, 0);
	tetra_create(5, 1, 1, 0);
	tetra_create(5, 2, 1, 1);
	tetra_create(5, 3, 2, 1);
	tetra_create(6, 0, 0, 0);
	tetra_create(6, 1, 1, 0);
	tetra_create(6, 2, 0, 1);
	tetra_create(6, 3, 0, 2);
}

void	create_second_part(void)
{
	tetra_create(7, 0, 0, 0);
	tetra_create(7, 1, 1, 0);
	tetra_create(7, 2, 1, 1);
	tetra_create(7, 3, 1, 2);
	tetra_create(8, 0, 0, 0);
	tetra_create(8, 1, 0, 1);
	tetra_create(8, 2, 1, 1);
	tetra_create(8, 3, 2, 1);
	tetra_create(9, 0, 0, 0);
	tetra_create(9, 1, 0, 1);
	tetra_create(9, 2, 1, 1);
	tetra_create(9, 3, 0, 2);
	tetra_create(10, 0, 0, 0);
	tetra_create(10, 1, 0, 1);
	tetra_create(10, 2, 1, 1);
	tetra_create(10, 3, 1, 2);
	tetra_create(11, 0, 0, 0);
	tetra_create(11, 1, 0, 1);
	tetra_create(11, 2, 0, 2);
	tetra_create(11, 3, 1, 2);
	tetra_create(12, 0, 0, 0);
	tetra_create(12, 1, 0, 1);
	tetra_create(12, 2, 0, 2);
	tetra_create(12, 3, 0, 3);
}

void	create_third_part(void)
{
	tetra_create(13, 0, 1, 0);
	tetra_create(13, 1, 2, 0);
	tetra_create(13, 2, 0, 1);
	tetra_create(13, 3, 1, 1);
	tetra_create(14, 0, 1, 0);
	tetra_create(14, 1, 0, 1);
	tetra_create(14, 2, 1, 1);
	tetra_create(14, 3, 2, 1);
	tetra_create(15, 0, 1, 0);
	tetra_create(15, 1, 0, 1);
	tetra_create(15, 2, 1, 1);
	tetra_create(15, 3, 0, 2);
	tetra_create(16, 0, 1, 0);
	tetra_create(16, 1, 0, 1);
	tetra_create(16, 2, 1, 1);
	tetra_create(16, 3, 1, 2);
	tetra_create(17, 0, 1, 0);
	tetra_create(17, 1, 1, 1);
	tetra_create(17, 2, 0, 2);
	tetra_create(17, 3, 1, 2);
	tetra_create(18, 0, 2, 0);
	tetra_create(18, 1, 0, 1);
	tetra_create(18, 2, 1, 1);
	tetra_create(18, 3, 2, 1);
}

t_tetra	*tetriminos(void)
{
	g_tetra = (t_tetra*)malloc(sizeof(t_tetra) * 19);
	if (!g_tetra)
		return (NULL);
	tetra_create(0, 0, 0, 0);
	tetra_create(0, 1, 1, 0);
	tetra_create(0, 2, 2, 0);
	tetra_create(0, 3, 3, 0);
	create_first_part();
	create_second_part();
	create_third_part();
	return (g_tetra);
}
