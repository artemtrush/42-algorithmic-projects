/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:07:25 by atrush            #+#    #+#             */
/*   Updated: 2016/12/17 15:07:34 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		detect_second_true(char *map, int i, int j)
{
	if (map[i * 5 + j + 2] == '#')
	{
		if (map[(i + 1) * 5 + j] == '#')
			return (1);
		else if (map[(i + 1) * 5 + j + 1] == '#')
			return (2);
		else if (map[(i + 1) * 5 + j + 2] == '#')
			return (3);
	}
	else if (map[(i + 1) * 5 + j + 1] == '#')
	{
		if (map[(i + 1) * 5 + j] == '#')
			return (4);
		else if (map[(i + 1) * 5 + j + 2] == '#')
			return (5);
		else if (map[(i + 2) * 5 + j + 1] == '#')
			return (7);
	}
	else if ((map[(i + 1) * 5 + j] == '#') &&
			(map[(i + 2) * 5 + j] == '#'))
		return (6);
	return (-1);
}

int		detect_second_false(char *map, int i, int j)
{
	if (map[(i + 1) * 5 + j + 1] == '#')
	{
		if (map[(i + 1) * 5 + j + 2] == '#')
			return (8);
		else if (map[(i + 2) * 5 + j] == '#')
			return (9);
		else if (map[(i + 2) * 5 + j + 1] == '#')
			return (10);
	}
	else if (map[(i + 2) * 5 + j] == '#')
	{
		if (map[(i + 2) * 5 + j + 1] == '#')
			return (11);
		else if (map[(i + 3) * 5 + j] == '#')
			return (12);
	}
	return (-1);
}

int		detect_first_true(char *map, int i, int j)
{
	if (map[i * 5 + j + 1] == '#')
	{
		if ((map[i * 5 + j + 2] == '#') && (map[i * 5 + j + 3] == '#'))
			return (0);
		else
			return (detect_second_true(map, i, j));
	}
	else if (map[(i + 1) * 5 + j] == '#')
		return (detect_second_false(map, i, j));
	return (-1);
}

int		detect_first_false(char *map, int i, int j)
{
	if ((map[(i + 1) * 5 + j] == '#') && (map[i * 5 + j + 1] == '#'))
	{
		if (map[i * 5 + j + 2] == '#')
			return (13);
		else if (map[(i + 1) * 5 + j + 2] == '#')
			return (14);
		else if (map[(i + 2) * 5 + j] == '#')
			return (15);
		else if (map[(i + 2) * 5 + j + 1] == '#')
			return (16);
	}
	else if ((map[i * 5 + j + 1] == '#') && (map[(i + 2) * 5 + j] == '#') &&
			(map[(i + 2) * 5 + j + 1] == '#'))
		return (17);
	else if ((map[i * 5 + j + 2] == '#') && (map[(i + 1) * 5 + j] == '#') &&
			(map[(i + 1) * 5 + j + 2] == '#'))
		return (18);
	return (-1);
}

int		detect_tetra(char *map, int i, int j)
{
	if (map[i * 5 + j] == '#')
		return (detect_first_true(map, i, j));
	else if (map[(i + 1) * 5 + j + 1] == '#')
		return (detect_first_false(map, i, j));
	return (-1);
}
