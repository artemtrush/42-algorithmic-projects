# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrush <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 17:28:20 by atrush            #+#    #+#              #
#    Updated: 2016/12/09 12:53:48 by atrush           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.
OBJECTS =						\
			./ft_printf.o		\
			./checks.o			\
			./dependet_on_type.o\
			./ft_itoa.o			\
			./other_functions.o	\
			./print.o			\
			./types.o			\

all : $(NAME)
$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
