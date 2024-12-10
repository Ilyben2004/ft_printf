CC = cc 
CFLAGS = -Wall -Wextra -Werror 
SRCS = ft_putchar_fd.c  ft_putnbr_fd.c  ft_putstr_fd.c  hexsize.c ft_printf.c  ft_putadersse.c  ft_puthex.c      ft_putrevstr.c  ft_strlen.c
BSRCS = ${SRCS:.c=.o}
NAME = libftprintf.a


all:${NAME}

${NAME}:${BSRCS}
	ar rcs ${NAME} ${BSRCS}

clean :
	rm -rf ${BSRCS}

fclean: clean
	rm -rf ${NAME}

re : fclean all
