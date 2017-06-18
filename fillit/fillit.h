/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:58:04 by atrush            #+#    #+#             */
/*   Updated: 2016/12/12 17:11:55 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_tetra
{
	int			x[4];
	int			y[4];
}				t_tetra;

t_tetra			*tetriminos(void);
void			ft_putstr(char const *s);
char			*create_map(int *mas, t_tetra *figures);
int				*read_file(int fd);
int				detect_tetra(char *map, int i, int j);
int				ft_sqr(int num);
void			definition_of_the_beginning(int k, int *w, int *h, int size);

#endif
