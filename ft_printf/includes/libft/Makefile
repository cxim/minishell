# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 13:35:13 by mnarwhal          #+#    #+#              #
#    Updated: 2019/09/05 13:35:16 by mnarwhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
					ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
					ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
					ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
					ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
					ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
					ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
					ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
					ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
					ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
					ft_strtrim.c ft_tolower.c ft_toupper.c ft_strlen_unilsymb.c \
					ft_word_count.c ft_memfree.c ft_count_if.c get_next_line.c \
					ft_new_integer_list.c ft_putchar_mod.c ft_char_in_string.c \
					ft_cut_space.c ft_get_integer.c ft_strlen_mod.c ft_putstr_mod.c \
					ft_numzero.c ft_print_symbol.c ft_itoa_long.c ft_strsplit_len.c \
					ft_split.c ft_str_is_num.c ft_isspace.c new_gnl.c

FLAGS = gcc -c -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
