C_FLAGS =  -I
NAME = minishell
SRCS = main.c
##-Wall -Werror -Wextra
OBJECTS = $(SRCS:.c=.o)
LIBFT = ft_printf/
HEADER = ft_printf/includes/printf.h
LIB = ft_printf/libftprintf.a


all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	gcc -o $(NAME) $(OBJECTS) $(LIB)

$(OBJECTS):	%.o: %.c
	clang -g $(C_FLAGS) $(HEADER) -o $@ -c $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
