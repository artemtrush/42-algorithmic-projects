/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:14:51 by atrush            #+#    #+#             */
/*   Updated: 2017/03/24 16:14:54 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE	42
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"

# include <unistd.h>
# include <stdlib.h>
# include "./../libft/libft.h"

typedef	struct		s_link
{
	char			*room;
	struct s_link	*next;
}					t_link;

typedef	struct		s_text
{
	char			*text;
	struct s_text	*next;
}					t_text;

typedef	struct		s_room
{
	int				start_or_end;
	char			*room;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef	struct		s_road
{
	int				ant;
	char			*room;
	struct s_road	*next;
	struct s_road	*prev;
}					t_road;

typedef	struct		s_ways
{
	int				id;
	int				diff_lvl;
	t_road			*road;
	struct s_ways	*next;
}					t_ways;

typedef	struct		s_gnl
{
	int				fd;
	char			buf[BUFF_SIZE];
	int				size;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					delete_road(t_road **root);
int					delete_ways(t_ways **root);
int					delete_room(t_room **root);
int					delete_text(t_text **root);
int					delete_link(t_link **root);
int					delete_all(t_text **text, t_ways **ways,
					t_room **room, char **line);
int					create_road(t_road **root, char *room);
int					create_ways(t_ways **root);
int					create_text(t_text **root, char *text);
int					create_room(t_room **root, char *name, int start_end);
int					reading(t_ways **ways, int *ant);
int					print_text(t_text **text, t_room **room, char **line);
int					check_line_for_int(char *line, char c);
int					is_it_link(const char *line, t_room *tmp);
int					read_rooms(t_text **text, t_room **room, char **line);
int					read_links(t_text **text, t_room **room, char **line);
void				delete_unnecessary(t_ways **ways);
void				road_to_the_hellend(t_ways **ways, int ant);
int					check_coords(t_text *text);
int					find_min_way(t_ways *ways);
void				run_ant_run(t_ways **ways);
int					count_crossroads(t_ways *ways, int id, int crossroads);
void				remove_crossroads(t_ways **ways);
void				swap_room_nodes(t_room **root, int node);
int					start(t_road **road, t_room *room);
void				print_step(int *already_printed, int ant, const char *str);
int					build_walkways(t_ways **ways, t_room *room);
void				tmp_free(t_road	**tmp);
void				norma(char **line);
int					this_have_not_happened_before(t_road *road,
					const char *room);

#endif
