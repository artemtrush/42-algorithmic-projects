/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:55:10 by atrush            #+#    #+#             */
/*   Updated: 2016/12/17 15:07:58 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			g_k;
t_tetra		*g_tet;

char	*new_map(void)
{
	char	*map;
	int		n;
	int		i;

	n = g_k * (g_k + 1);
	if (!(map = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	map[n] = '\0';
	i = 0;
	while (i < n)
	{
		if ((i + 1) % (g_k + 1) == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	return (map);
}

int		check_other(int t, int w, int h, char *map)
{
	int i;

	i = 1;
	while (i < 4)
	{
		if (g_tet[t].y[i] + h >= g_k)
			return (0);
		if (g_tet[t].x[0] + w >= g_k)
			return (0);
		if (map[(g_tet[t].y[i] + h) * (g_k + 1) + g_tet[t].x[i] + w] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		find_place(int t, char *map, char c, int k)
{
	int w;
	int h;
	int i;

	definition_of_the_beginning(k, &w, &h, g_k);
	while (g_tet[t].y[0] + h < g_k)
	{
		while (g_tet[t].x[0] + w < g_k)
		{
			if (map[(g_tet[t].y[0] + h) * (g_k + 1) + g_tet[t].x[0] + w] == '.')
				if (check_other(t, w, h, map))
				{
					i = -1;
					while (++i < 4)
						map[(g_tet[t].y[i] + h) * (g_k + 1) +
							g_tet[t].x[i] + w] = c;
					return (h * (g_k + 1) + w);
				}
			w++;
		}
		w = 0;
		h++;
	}
	return (-1);
}

int		set_tetriminos(int *mas, char *map, int step, char *letters)
{
	int i;
	int k;

	k = -1;
	if (step > mas[0])
		return (1);
	while ((k = find_place(mas[step], map, letters[step - 1], k)) != -1)
	{
		if (set_tetriminos(mas, map, step + 1, letters))
			return (1);
		i = 0;
		while (map[i])
		{
			if (map[i] == letters[step - 1])
				map[i] = '.';
			i++;
		}
	}
	return (0);
}

char	*create_map(int *mas, t_tetra *figures)
{
	char	*map;
	char	*letters;
	int		i;

	if (!(letters = (char*)malloc(sizeof(char) * (mas[0] + 1))))
		return (NULL);
	g_tet = figures;
	g_k = ft_sqr(mas[0] * 4);
	i = -1;
	while (++i < mas[0])
		letters[i] = 65 + i;
	letters[i] = '\0';
	while ((map = new_map()))
	{
		if (set_tetriminos(mas, map, 1, letters))
		{
			free(letters);
			return (map);
		}
		g_k++;
		free(map);
	}
	free(letters);
	return (NULL);
}
