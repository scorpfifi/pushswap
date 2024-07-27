NAME = push_swap
CC = gcc -g
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRC_1 = push_swap.c ft_stack_utils.c ft_utils.c ft_push.c ft_reverse.c ft_rotate.c ft_swap.c ft_sort_three.c ft_sort_big.c ft_utils_found.c ft_sort_utils.c ft_check_error.c
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
