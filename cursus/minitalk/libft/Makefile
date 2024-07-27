SRCS	= ft_printf.c ft_putbase.c ft_putnumber.c ft_putstring.c ft_strlen.c

OBJS	= ${SRCS:.c=.o}


NAME	= libft.a

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:    ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME} $(BONUS_OBJS)

re : fclean all
