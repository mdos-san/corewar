# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 16:33:50 by ajubert           #+#    #+#              #
#    Updated: 2017/02/25 14:07:32 by jcao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=			libft.a

COMPILER=		gcc

FLAGS=			-Wall -Wextra -Werror

HEADER =		$(FT_SRC_DIR)libft.h		$(FT_SRC_DIR)get_next_line.h

FT_SRC_DIR =	./libft/

PRINTF_HEADER =	$(PRINTF_DIR)ft_printf.h

PRINTF_DIR =	./printf/

FT_COMPILED =	ft_memset.o\
				ft_bzero.o\
				ft_memcpy.o\
				ft_memccpy.o\
				ft_memmove.o\
				ft_memchr.o\
				ft_memcmp.o\
				ft_strlen.o\
				ft_strcpy.o\
				ft_strncpy.o\
				ft_strcat.o\
				ft_strncat.o\
				ft_strlcat.o\
				ft_strchr.o\
				ft_strrchr.o\
				ft_strstr.o\
				ft_strnstr.o\
				ft_strcmp.o\
				ft_strncmp.o\
				ft_isalpha.o\
				ft_isdigit.o\
				ft_isalnum.o\
				ft_isascii.o\
				ft_isprint.o\
				ft_toupper.o\
				ft_tolower.o\
				ft_atoi.o\
				ft_memalloc.o\
				ft_memdel.o\
				ft_strnew.o\
				ft_strdel.o\
				ft_strclr.o\
				ft_striter.o\
				ft_striteri.o\
				ft_strmap.o\
				ft_strmapi.o\
				ft_strequ.o\
				ft_strnequ.o\
				ft_strdup.o\
				ft_strsub.o\
				ft_strjoin.o\
				ft_strtrim.o\
				ft_putchar.o\
				ft_putchar_fd.o\
				ft_putstr.o\
				ft_putstr_fd.o\
				ft_putendl.o\
				ft_putendl_fd.o\
				ft_strsplit.o\
				ft_putnbr.o\
				ft_putnbr_fd.o\
				ft_itoa.o\
				ft_lstnew.o\
				ft_lstdelone.o\
				ft_lstdel.o\
				ft_lstadd.o\
				ft_lstiter.o\
				ft_lstmap.o\
				ft_lstnew_cpy.o\
				get_next_line.o\
				ft_iterative_power.o\
				ft_swap_char.o\
				ft_itoa_long_long.o\
				ft_unsigned_itoa.o\
				ft_unsigned_long_itoa.o\
				ft_wstrlen.o\
				ft_putstr_size.o\
				ft_strjoin_size.o\
				ft_strnncpy.o\
				ft_strdup_free.o\
				ft_strjoin_free.o\
				ft_atoi_long.o\
				ft_putstr_size_fd.o\
				ft_swap_int.o\
				ft_itoa_base.o\
				ft_isspace.o\

PRINTF_CMP = ft_printf.o\
			ft_printf_p.o\
			ft_list_printf.o\
			ft_flags.o\
			ft_before_modif_longueur.o\
			ft_printf_ch.o\
			ft_print_string.o\
			ft_printf_ent.o\
			ft_printf_octal.o\
			ft_printf_hexa.o\
			ft_printf_calc.o\
			ft_modif_longueur.o\
			ft_precision.o\
			ft_taille_min.o\
			ft_plus.o\
			ft_printf_wint.o\
			ft_printf_wc.o\
			ft_printf_fd.o\

COMPIL =		$(FT_COMPILED) $(PRINTF_CMP)

all: $(NAME)

$(NAME): $(COMPIL)
	ar rc $(NAME) $(COMPIL)
	ranlib $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)%.c $(HEADER)
	$(COMPILER) -c $(FLAGS) -I $(FT_SRC_DIR) $<

$(PRINTF_CMP): %.o: $(PRINTF_DIR)%.c $(PRINTF_HEADER)
	$(COMPILER) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_DIR) $<

clean:
	rm -rf $(COMPIL)

fclean: clean
	rm -rf $(NAME)

re: fclean all
