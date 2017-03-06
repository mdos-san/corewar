# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcao <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:13:26 by jcao              #+#    #+#              #
#    Updated: 2017/03/06 15:41:12 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all, clean, fclean, re

NAME = asm

SRC = main.c print_lexical.c check_name_str.c print_syntax.c lexical_error.c \
	syntax_error.c create_list.c seek_instruc.c escape_space.c check_str.c \
	live.c next_str.c check_dir.c check_list.c next_str_spe.c check_ind.c \
	check_reg.c next_str_error.c first_check.c next_check.c ld.c check_sep.c \
	error_type.c st.c and_instruc.c or_instruc.c aff.c add.c ldi.c lfork.c \
	lld.c lldi.c sti.c print_errors.c check_normal.c stock_read.c \
	check_dots.c check_end_instruc.c extension.c print_label_chars.c \
	convert.c count_nb_instruct.c count_octet.c create_header.c free_line.c \
	free_liste_op.c free_split.c free_tab.c ft_count_to.c ft_free_all.c \
	ft_strsplit_asm.c ft_yo_ne_se_pa.c init_liste_op.c list1.c op_or_ft.c \
	print_prog.c recup_file.c search_code.c write_file.c opcode.c \
	create_tab.c create_headerfin.c

OBJ = $(SRC:.c=.o)

INC = corewar_asm.h

CC = clang

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

LIBFT = libft/libft.a

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I corewar_asm.h -c $<

deb:
	make -C libft
	$(CC) -g -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT)

clean: 
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean 
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
