NAME = fractol
CC = gcc -g
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRC_1 = fractol.c
OBJ_1 = ${SRC_1:.c=.o}
INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	make -C ./libft
	$(MAKE) -C mini
	${CC} ${FLAGS} ${OBJ_1} -Lmini -lmlx_Linux -lXext -lX11 -lm -lz -o ${NAME} ${INCLUDE}
all: ${NAME}

clean:
	${RM} ${OBJ_1}
	@cd ./libft && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd ./libft && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re