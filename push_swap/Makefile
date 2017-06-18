F_NAME = checker
S_NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc/

ALL_SRC =									\
		./src/commands.c					\
		./src/execs.c						\
		./src/list.c						\
		./src/other_func.c					\
		./src/magic.c						\
		./src/dst_first_part.c				\
		./src/dst_second_part.c				\
		./src/instructions_first_part.c		\
		./src/instructions_second_part.c	\
		./src/search_in_stack.c				\
		./src/check_before_dst.c			\
		./src/join_implementation.c			\
		./src/throw_all.c					\
		./src/get_next_line.c				\
		./src/pls_do_not_open.c				\
		./src/pleasant_viewing.c			\
		./src/sizes.c						\
		./src/quick_check.c					\
		./src/print.c						\
		./src/instr_list.c					\
		
F_SRC = ./src/checker.c
S_SRC = ./src/push_swap.c

F_OBJ = $(subst .c,.o,$(subst src/,obj/,$(ALL_SRC) $(F_SRC)))
S_OBJ = $(subst .c,.o,$(subst src/,obj/,$(ALL_SRC) $(S_SRC)))
	
all: $(F_NAME) $(S_NAME)

$(F_NAME): $(F_OBJ)
	@$(CC) -o $(F_NAME) $(F_OBJ)
	
$(S_NAME): $(S_OBJ)
	@$(CC) -o $(S_NAME) $(S_OBJ)
	@printf "\033[33m\nDone.\n\033[0m"

obj/%.o: src/%.c
	@mkdir obj 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\033[42m  \033[0m"

clean:
	@rm -rf $(F_OBJ) ./obj/push_swap.o
	@echo "\033[31mСleaning completed\033[0m"
	@rmdir obj

fclean: clean
	@rm -rf $(F_NAME) $(S_NAME)
	@echo "\033[31mPrograms removed\033[0m"

re: fclean recg all

recg:
	@printf "\033[33mRecompiling...\n\033[0m"
