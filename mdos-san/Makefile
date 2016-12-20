FLAG	=		-Wextra -Werror -Wall
I		=		-I./includes
L		=		-L./libs -lftprintf

SRC_O	=  main.o

all:    corewar

corewar:    libs/libftprintf.a includes/libftprintf.h includes/libft.h $(SRC_O)
	gcc $(FLAG) $(I) $(L) -o corewar $(SRC_O)
includes/libftprintf.h:
	cp libs/libftprintf/includes/libftprintf.h includes

includes/libft.h:
	cp libs/libftprintf/includes/libft.h includes

libs/libftprintf.a:
	make re -C libs/libftprintf
	cp libs/libftprintf/libftprintf.a libs
	make fclean -C libs/libftprintf

%.o:    srcs/%.c
	gcc -c $< $(FLAG) $(I)

clean:
	rm -rf $(SRC_O)

fclean:	clean
	rm -rf corewar
	rm -rf includes/libft.h includes/libftprintf.h
	rm -rf libft/libftprintf.a

re:	fclean all