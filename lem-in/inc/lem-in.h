#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE	42
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"

# include <unistd.h>
# include <stdlib.h>
# include "./../libft/libft.h"

typedef	struct		s_room
{
	int				start_or_end;
	char			*room;
	char			**links;
	struct s_room	*next;
}					t_room;

typedef	struct		s_road
{
	int				ant;
	char			*room;
	struct s_road	*next;
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
void				delete_road(t_road **root);
int					delete_ways(t_ways **root);
int					create_road(t_road **root, char *room);
int					create_way(t_ways **root, int id);
int					reading(t_ways **ways);

#endif
