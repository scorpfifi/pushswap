NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRC_1 = ft_check_args.c ft_main.c ft_push.c ft_reverse.c ft_rotate.c ft_swap.c ft_utils_error.c ft_utils.c ft_sort_threestack.c ft_sort_big.c
OBJ_1 = ${SRC_1:.c=.o}
INCLUDE = -L ./libft_bonus -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	make -C ./libft_bonus
	${CC} ${FLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}
all: ${NAME}

clean:
	${RM} ${OBJ_1} ${NAME}
	@cd ./libft_bonus && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd ./libft_bonus && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re