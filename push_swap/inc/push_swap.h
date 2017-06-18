/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:25:12 by atrush            #+#    #+#             */
/*   Updated: 2017/02/11 11:59:57 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MIN_INT	-2147483648
# define MAX_INT	2147483647
# define BUFF_SIZE	13
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;30;43m"
# define BLUE		"\033[1;30;44m"
# define BLACK		"\033[1;37;40m"
# define AMOUNT		"\033[1;33m"
# define RESET_AT	"\033[0m\n"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_list
{
	long long		num;
	int				size;
	struct s_list	*next;
}					t_list;

typedef struct		s_instr
{
	char			action[4];
	struct s_instr	*next;
}					t_instr;

typedef	struct		s_gnl
{
	int				fd;
	char			buf[BUFF_SIZE];
	int				size;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
long long			ft_atol(const char *nptr);
int					delete_list(t_list	**list);
t_list				*create_list(int argc, char **argv, int fg);
void				exec_sa_sb(t_list **stack);
void				exec_pa_pb(t_list **stack_from, t_list **stack_on);
void				exec_ra_rb(t_list **stack);
void				exec_rra_rrb(t_list **stack);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strlen(const char *str);
int					check(t_list *stack_a, t_list *stack_b);
int					exec_commands(t_list **stack_a, t_list **stack_b,
					int flag, int fd);
int					valid_command(char *buf, t_list **stack_a,
					t_list **stack_b);
long long			last(t_list *stack, int fg);
long long			find_first_min(t_list *stack);
long long			find_max(t_list *stack);
int					count_stack(t_list *stack);
int					check_flags(char *str, int **flags);
void				print_stacks(t_list *stack_a, t_list *stack_b,
					int flag, char *str);
void				print_instr(t_instr *com, int fd);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);

void				new_beautiful_algo(t_list **stack_a, t_list **stack_b,
					int flag, int fd);
int					count_sizes(t_list *stack);
void				up_sizes(t_list **stack);
void				align_sizes(t_list **stack);
int					yet_elems(t_list *stack, long long avg, int size);
long long			find_avg(t_list *stack);
int					a_sort(t_list *stack_a);
int					maybe_swap(t_list *stack, long long avg, int size);
int					mb_just_swap(t_list **stack_a, t_list **stack_b,
					t_instr **com);
void				do_wrt(char *str, t_list **stack_a, t_list **stack_b,
					t_instr **com);
int					new_com(t_instr **com, char *str);
void				delete_instr(t_instr **com);
void				remove_unnecessary(t_instr **com);
int					count_instr(t_instr *stack);
int					ft_ne_norma(t_instr *tmp);

void				old_terrible_algo(t_list **stack_a, t_list **stack_b,
					int flag, int fd);
int					find_in_one_stack(t_list *stack, long long elem);
int					find_in_two_stacks(t_list *st_1, t_list *st_2,
					long long elem);
void				magic(t_list **stack_a, t_list **stack_b, t_instr **com);
long long			dst_to_elem(t_list **stack, long long elem);
void				do_cmd(char *str, t_list **stack_a, t_list **stack_b,
					t_instr **com);
int					check_fg(long long *elem);
void				write_com(char *str, t_list **stack_a, t_list **stack_b,
					t_instr **com);

void				join_implementation_rr(t_list **st_a, t_list **st_b,
					long long elem, t_instr **com);
void				join_implementation_rrr(t_list **st_a, t_list **st_b,
					long long elem, t_instr **com);
void				join_stacks(t_list **stack_a, t_list **stack_b,
					t_instr **com);
int					small_size(t_list *stack, long long elem);

long long			throw_up(t_list *stack, long long elem, int fg);
long long			throw_down(t_list *stack, long long elem, int fg);
long long			throw_edges(t_list *stack, long long elem, int fg);

long long			dst_two_up(t_list *st_a, t_list *st_b, long long elem);
long long			dst_two_down(t_list *st_a, t_list *st_b, long long elem);
long long			dst_up_down(t_list *st_1, t_list *st_2,
					long long elem, int fg);
long long			dst_just_up(t_list *st_1, t_list *st_2,
					long long elem, int fg);
long long			dst_just_down(t_list *st_1, long long elem, int fg);
long long			dst_throw_all(t_list *stack, long long elem, int fg);
long long			dst_swap(t_list *stack, long long elem, int fg);

void				two_up(t_list **st_a, t_list **st_b, long long elem,
					t_instr **com);
void				two_down(t_list **st_a, t_list **st_b, long long elem,
					t_instr **com);
void				up_down(t_list **st_1, t_list **st_2, long long elem,
					t_instr **c);
void				up_down_end(t_list **st_1, t_list **st_2, int fg,
					t_instr **com);
void				just_up(t_list **st_1, t_list **st_2, long long elem,
					t_instr **com);
void				just_down(t_list **st_1, t_list **st_2, long long elem,
					t_instr **com);
void				throw_all(t_list **st_1, t_list **st_2, long long elem,
					t_instr **c);
void				swap(t_list **st_1, t_list **st_2, long long elem,
					t_instr **c);
void				swap_two_elems(t_list **st_1, t_list **st_2, int fg,
					t_instr **c);

#endif
