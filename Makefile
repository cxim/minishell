C_FLAGS =  -I
NAME = minishell
SRCS = main.c free.c loop.c my_split.c todo_cd.c todo_set_env.c echo_exec.c exec_bin.c set_enveron.c unset_enveron.c
G_FLAGS = -Wall -Werror -Wextra
OBJECTS = $(SRCS:.c=.o)
LIBFT = ft_printf/
HEADER = ft_printf/includes/printf.h
LIB = ft_printf/libftprintf.a


all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	gcc -o $(NAME) $(OBJECTS) $(LIB)

$(OBJECTS):	%.o: %.c
	clang -g  $(C_FLAGS) $(HEADER) -o $@ -c $<
	clang -g $(G_FLAGS) $(C_FLAGS) $(HEADER) -o $@ -c $<

clean:
	make clean -C $(LIBFT)
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re: fclean all
