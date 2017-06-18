/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:17:39 by atrush            #+#    #+#             */
/*   Updated: 2016/12/17 13:13:16 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_tetra		*tetra;
	int			*mas;
	char		*map;

	if (argc != 2)
		ft_putstr("usage: ./fillit target_file\n");
	else if ((fd = open(argv[1], O_RDONLY)) != -1)
		if ((mas = read_file(fd)))
		{
			if ((tetra = tetriminos()))
			{
				if ((map = create_map(mas, tetra)))
				{
					ft_putstr(map);
					free(map);
					argc = 0;
				}
				free(tetra);
			}
			free(mas);
		}
	if (argc == 2)
		ft_putstr("error\n");
	return (0);
}
