CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf

SRC = ast_execute_cmd.c 		\
	  ast_execute_built.c 		\
	  ast_execute.c 			\
	  ast_find_type.c 			\
	  ast_find_name_pos.c 		\
	  ast_generate.c 			\
	  ast_gen_args.c 			\
	  ast_node_gen_cmd.c		\
	  ast_node_gen_builtin.c	\
	  ast_node_gen_redir.c		\
	  ast_node_create.c 		\
	  ast_node_destroy.c 		\
	  ast_node_redirect.c 		\
	  ast_handle_pipe.c 		\
	  ast_setup_all_pipes.c		\
	  ast_setup_all_redirs.c	\
	  ast_print.c	 			\
	  ast_wait.c	 			\
	  error_put.c				\
	  redir_create_i.c			\
	  redir_create_o.c			\
	  redir_create_h.c			\
	  redir_create_a.c			\
	  redir_create.c			\
	  builtin_cd.c 				\
	  builtin_echo.c 			\
	  builtin_env.c				\
	  builtin_pwd.c				\
	  builtin_export.c			\
	  builtin_exit.c			\
	  builtin_unset.c			\
	  dq_mode.c					\
	  main.c					\
	  match_wildcard.c			\
	  ms_getenv.c 				\
	  ms_getenv_cont.c 			\
	  ms_gen_prompt.c 			\
	  get_full_cmd.c			\
	  ms_envsetup.c				\
	  signal.c					\
	  agregate_spaces.c			\
	  agregate_redirs.c			\
	  expand_wildcards.c		\
	  expand_one.c				\
	  export_without_args.c		\
	  token_create.c			\
	  token_destroy.c 			\
	  token_void_dest.c 		\
	  token_gen_content.c 		\
	  token_handle_pipe.c 		\
	  token_handle_word.c 		\
	  token_handle_and.c 		\
	  token_handle_redir_i.c 	\
	  token_handle_redir_o.c 	\
	  token_handle_var.c	 	\
	  token_handle_brackets.c 	\
	  token_handle_tilde.c	 	\
	  token_handle_space.c	 	\
	  tokenizer_create.c 		\
	  tokenizer_destroy.c		\
	  tokenizer_next_token.c	\
	  tokenizer_parse.c			\
	  tokenizer_as_array.c		\
	  tokenize_input.c			\
	  tokens_size.c				\
	  tokens_is_control.c		\
	  tokens_check_syntax.c		\
	  tokens_check_brackets.c	\
	  tokens_print.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = minishell

INCLUDES = -Iinclude/
LIB = libft.a

%.o: %.c
ifeq ($(shell whoami), graux)
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ -I/goinfre/graux/.brew/opt/readline/include
else ifeq ($(shell whoami), julienlaiti)
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ -I/opt/homebrew/opt/readline/include
else
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ -I$(HOME)/.brew/opt/readline/include
endif

all: ${NAME}

${LIB}:
	cd libft/ && make && cp -v libft.a ../

$(NAME): ${LIB} $(OBJ)
ifeq ($(shell whoami), graux)
	$(CC) ${FLAGS} $(OBJ) $(INCLUDES) -I/goinfre/graux/.brew/opt/readline/include -L. -L/goinfre/graux/.brew/opt/readline/lib -lft -lreadline -o $(NAME)
else ifeq ($(shell whoami), julienlaiti)
	$(CC) ${FLAGS} $(OBJ) $(INCLUDES) -I/opt/homebrew/opt/readline/include -L. -L/opt/homebrew/opt/readline/lib -lft -lreadline -o $(NAME)
else
	$(CC) ${FLAGS} $(OBJ) $(INCLUDES) -I$(HOME)/.brew/opt/readline/include -L. -L$(HOME)/.brew/opt/readline/lib -lft -lreadline -o $(NAME)
endif

re: fclean all

clean:
	cd libft/ && make clean
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME}
	${RM} ${LIB}

.PHONY: all re clean fclean
