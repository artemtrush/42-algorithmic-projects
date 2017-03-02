NAME = lem-in
CC = gcc
CFG = -Wall -Wextra -Werror -I./inc/
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a

SRC =								\
		./src/lem-in.c				\
		./src/get_next_line.c		\
		./src/list.c				\
		./src/room.c				\
		./src/reading.c				\

OBJ = $(subst .c,.o,$(subst src/,obj/,$(SRC)))
	
all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L./ft_printf -lftprintf -L./libft -lft
	@printf "\033[33m\nDone.\n\033[0m"

$(LIBFT):
	@$(MAKE) -C ./libft/ 1> /dev/null 2> /dev/null || true

$(FT_PRINTF):
	@$(MAKE) -C ./ft_printf/ 1> /dev/null 2> /dev/null || true

obj/%.o: src/%.c
	@mkdir obj 2> /dev/null || true
	@$(CC) $(CFG) -o $@ -c $<
	@printf "\033[42m  \033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31mСleaning completed\033[0m"
	@rmdir obj 2> /dev/null || true
	@$(MAKE) -C ./libft/ clean 1> /dev/null || true
	@$(MAKE) -C ./ft_printf/ clean 1> /dev/null || true
	
fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mPrograms removed\033[0m"
	@$(MAKE) -C ./libft/ fclean 1> /dev/null || true
	@$(MAKE) -C ./ft_printf/ fclean 1> /dev/null || true

re: fclean recg all

recg:
	@printf "\033[33mRecompiling...\n\033[0m"