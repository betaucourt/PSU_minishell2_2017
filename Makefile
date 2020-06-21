##
## EPITECH PROJECT, 2017
## minishell
## File description:
## makefile
##

TOOLS =		./SRC/tools/get_line.c			\
			./SRC/tools/tools_2.c			\
			./SRC/tools/tools_3.c			\
			./SRC/tools/tools.c

SRC	=		./SRC/main.c					\
			./SRC/handle_env.c				\
			./SRC/commands/cd.c				\
			./SRC/commands/env.c			\
			./SRC/commands/setenv.c			\
			./SRC/commands/tools_env.c		\
			./SRC/commands/unsetenv.c		\
			./SRC/forks/simple_fork.c		\
			./SRC/forks/get_path.c			\
			./SRC/redir/double_left.c		\
			./SRC/redir/simple_left.c		\
			./SRC/redir/double_right.c		\
			./SRC/redir/simple_right.c		\
			./SRC/redir/pipe.c				\
			./SRC/redir/tools_redir.c		\
			./SRC/execut/execut_action.c	\
			./SRC/execut/simple_exec.c		\
			./SRC/parsing/first_split.c		\
			./SRC/parsing/first_checking.c	\
			./SRC/parsing/epur.c			\
			./SRC/parsing/second_pars.c		\
			./SRC/parsing/second_check.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME):
		gcc -g -W -Wall -Wextra -o $(NAME) $(TOOLS) $(SRC) -I./include -L./lib
		@$ echo -e "Compiling :" $(NAME) "[DONE]"

clean:
		rm -f $(OBJ)
		@$ echo -e "Clean : [DONE]"

fclean:		clean
		rm $(NAME) $(OBJS)

re:		fclean all
