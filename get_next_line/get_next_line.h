/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:52:33 by atrush            #+#    #+#             */
/*   Updated: 2016/12/21 15:53:58 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 666

# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	int				fd;
	char			buf[BUFF_SIZE];
	int				size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);

#endif
