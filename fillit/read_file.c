/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:10:06 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/17 15:08:07 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cut_tetra(char *map, int f)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (f == 0)
			{
				if (map[i * 5 + j] == '#')
					return (i);
			}
			else
			{
				if (map[j * 5 + i] == '#')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		valid_tetra(char *map)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (map[i] != '\n')
				return (-1);
		}
		else
		{
			if (map[i] == '#')
				count++;
			else if (map[i] != '.')
				return (-1);
		}
		i++;
	}
	if (count != 4)
		return (-1);
	return (detect_tetra(map, cut_tetra(map, 0), cut_tetra(map, 1)));
}

int		create_tetra_mas(int fd, int **mas, char *map)
{
	int		ret;
	int		count;

	count = 0;
	while (1)
	{
		ret = read(fd, map, 21);
		if (ret <= 19)
			break ;
		if (ret == 21)
			if (map[20] != '\n')
				break ;
		map[20] = '\0';
		count++;
		if (((*mas)[count] = valid_tetra(map)) == -1)
			break ;
		if (ret == 20)
		{
			(*mas)[0] = count;
			return (1);
		}
	}
	return (0);
}

int		*read_file(int fd)
{
	char	*map;
	int		*mas;

	if ((mas = (int *)malloc(sizeof(int) * 27)))
	{
		if ((map = (char *)malloc(sizeof(char) * 21)))
		{
			if (create_tetra_mas(fd, &mas, map))
			{
				close(fd);
				free(map);
				return (mas);
			}
			free(map);
		}
		free(mas);
	}
	close(fd);
	return (NULL);
}
