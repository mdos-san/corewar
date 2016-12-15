NAME	=	corewar

FLAGS	=	-I./includes #: -Werror -Wextra -Wall

TMP_C	=	check_error.c\
			get_comment.c\
			get_name.c\
			get_prog.c\
			intro_display.c\
			main.c\
			size_prog.c\
			stock_prog.c
SRC_C	=	$(TMP_C:%=srcs/%)
SRC_O	=	$(TMP_C:%.c=%.o)

all: $(NAME)

$(NAME): libft.a includes/libft.h $(SRC_O)

%.o:	srcs/%.c
	gcc $(FLAGS) -c $<

libft.a:
	make -C libft
	cp libft/libft.a .
	make fclean -C libft

includes/libft.h:
	cp libft/includes/libft.h includes

clean:
	rm -rf $(SRC_O)

fclean:	clean
	rm -rf libft.a
	rm -rf includes/libft.h
