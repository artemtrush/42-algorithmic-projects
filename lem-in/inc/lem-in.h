#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE	42
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;37;43m"
# define BLUE		"\033[1;37;44m"
# define BLACK		"\033[1;2;37;40m"

# include <unistd.h>
# include <stdlib.h>
# include "./../libft/libft.h"

typedef	struct		s_gnl
{
	int				fd;
	char			buf[BUFF_SIZE];
	int				size;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);

#endif
