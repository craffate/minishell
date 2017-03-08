NAME		=	minishell

SRCS_FILES	=	main.c \
				exec.c \
				builtins.c \
				builtins2.c \
				utils.c \
				utils2.c \
				handlers.c

LIBFT		=	libft.a

LIBFTPATH	=	./libft

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I./includes -I$(LIBFTPATH)/includes

SRCS		=	$(addprefix srcs/,$(SRCS_FILES))

all: $(NAME)

$(NAME): $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(INCLUDES) -L$(LIBFTPATH) -lft

$(LIBFT):
	@make -C $(LIBFTPATH)

clean:
	@make clean -C $(LIBFTPATH)

fclean: clean
	@make fclean -C $(LIBFTPATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean $(LIBFT)
