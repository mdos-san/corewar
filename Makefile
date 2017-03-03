FLAG	=		-Wextra -Werror -Wall #-fsanitize=address #-Weverything
I		=		-I./includes
L		=		-L./libs ./libs/libftprintf.a -lncurses

SRC_O	=		main.o\
				cw_init.o\
				write_to.o\
				exec_turn.o\
				asm_fct.o\
				bytecode_read.o\
				verbose_print.o\
				board_print.o\
				ocp_get.o\
				linked_list_process.o\
				dump.o\
				print_winner.o\
				parse.o\
				error.o

all:    corewar

corewar:    libs/libftprintf.a includes/libftprintf.h includes/libft.h $(SRC_O)
	gcc $(FLAG) -o corewar $(SRC_O) $(I) $(L)
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
	rm -rf libs/libftprintf.a
	rm -rf _out
	rm -rf _verbose_out
	rm -rf _ins_out _ins_zaz
	rm -rf error

re:	fclean all
