# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcao <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:13:26 by jcao              #+#    #+#              #
#    Updated: 2016/04/14 15:08:34 by jcao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isascii.c ft_isalpha.c ft_isdigit.c ft_bzero.c \
	  ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	  ft_strcat.c ft_strchr.c ft_strclr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	  ft_strlen.c ft_strmap.c ft_atoi.c ft_strlcat.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
	  ft_itoa.c ft_memalloc.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strsplit.c \
	  ft_strsub.c ft_strtrim.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	  ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_islower.c ft_ispunct.c \
	  ft_isspace.c ft_isupper.c ft_isxdigit.c ft_strnchr.c get_next_line.c \
	  ft_itoa_base.c c_conv.c check1.c check2.c display.c ft_printf.c \
	  min_char.c min_str.c s_conv.c di_conv.c min_pre.c ft_putstr.c \
	  ft_itoa_base.c ft_strnchr.c fucking_flag.c o_conv.c u_conv.c x_conv.c \
	  xmaj_conv.c str_upper.c dmaj_conv.c umaj_conv.c omaj_conv.c p_conv.c \
	  no_conv.c except_pre.c ft_itoa_ulong.c smaj_conv.c min_char0.c \
	  percent_conv.c free_str.c cmaj_conv.c unicode_mask.c split_tab.c \
	  conv_bin.c min_charuni.c unicode_masks.c test_len.c hashtag_x.c \
	  hashtag_o.c free_str3.c except_minus.c except_smaj.c \

OBJ = $(SRC:.c=.o)

INC = -I ./includes

CC = clang
CFLAGS = -Werror -Wall -Wextra

all: $(NAME) 

$(NAME):
	$(CC) $(INC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all
