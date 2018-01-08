##
## Makefile for Makefile in /home/chenne_a/rendu/CPE_2015_Pushswap
## 
## Made by Arthur Chennetier
## Login   <chenne_a@epitech.net>
## 
## Started on  Mon Nov 16 14:15:36 2015 Arthur Chennetier
## Last update Tue Jun  7 15:16:04 2016 arthur
##

SRC	=	minishell.c \
		init_shell.c \
		./usefull/useful.c \
		./usefull/my_getnbr.c \
		./usefull/get_next_line.c \
		./usefull/my_str_to_wordtab.c \
		./exec/path_functions.c \
		./exec/direct_functions.c \
		./build_in/build_in.c \
		./build_in/build_in2.c \
		./usefull/epur_str.c \
		./exec/many_exec.c \
		./exec/small_functions.c \
		./build_in/cd.c \
		./build_in/cd2.c \
		./build_in/globing.c \
		./build_in/init_globing.c \
		./build_in/curly_glob.c \
		./build_in/prepare_env.c \
		./build_in/echo.c \
		./build_in/my_echo.c \
		./build_in/backslash.c \
		./build_in/echo_tilde.c \
		./build_in/check_flags_history.c \
                ./build_in/flags_history.c \
		./build_in/history.c \
		./build_in/check_exit.c \
		./build_in/put_simple_list.c \
		./build_in/check_if_flag.c \
		./usefull/path_test_error.c \
		./build_in/setenv.c \
		./redirect/redirect_functions.c \
		./redirect/pipe_build_in.c \
		./redirect/prepare_functions.c \
		./redirect/semicolon_case.c \
		./redirect/simple_redirect.c \
		./tree_listes/create_tree.c \
		./tree_listes/create_liste.c \
		./tree_listes/add_del_env.c \
		./tree_listes/check_node.c \
		./redirect/multi_pipe.c \
		./redirect/double_pipe_and.c \
		./history/check_file.c \
		./history/flag_pars.c \
		./history/get_from_history.c \
		./history/list.c \
		./history/pars_com.c \
		./history/time.c \
		./history/dash_extend.c \
		./history/flag_str.c \
		./usefull/my_strcat.c \
		./usefull/str_to_wordtab.c \
		./usefull/int_to_str.c

RM	=	rm -f

CC	=	gcc

TEMP	=	$(SRC:.c=.c~)

NAME	=	42sh

CFLAGS	=	-W -Wall -Werror -Wextra -I./include

LDFLAGS	=	-L./lib/print -lprint

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
	make -C ./lib/print/
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C ./lib/print/
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean:		clean
	make fclean -C ./lib/print/
	$(RM) $(NAME)

re:		fclean all
