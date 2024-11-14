SRC	=	ft_chosefunc.c	ft_isalpha.c	ft_itoa.c	ft_print_diu.c	ft_print_sc.c	ft_printaddress.c	ft_printf.c	ft_printhex.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_strchr.c	ft_strlen.c	helper_func.c	printf_helper.c

OBJS	=	$(SRC:%.c=%.o)

FLAGS	=	-Wall	-Werror	-Wextra

NAME	=	libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar	rcs	$(NAME)	$(OBJS)

%.o:	%.c
	cc	-I.	$(FLAGS)	-c	$<

clean:
	rm	-f	$(OBJS)

fclean:	clean
	rm	-rf	$(NAME)

re:	fclean	all