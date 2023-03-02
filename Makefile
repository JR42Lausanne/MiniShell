CC = gcc
FLAGS = -Wall -Wextra -Werror -O2 -g
RM = rm -rf

SRC = ast_execute_cmd.c 		\
	  ast_execute_built.c 		\
	  ast_execute.c 			\
	  builtin_echo.c 			\
	  builtin_env.c				\
	  builtin_pwd.c				\
	  ms_getenv.c 				\
	  token_create.c			\
	  token_destroy.c 			\
	  token_void_dest.c 		\
	  token_gen_content.c 		\
	  tokenizer_create.c 		\
	  tokenizer_destroy.c		\
	  tokenizer_next_token.c	\
	  tokenizer_parse.c			\
	  tokenizer_as_array.c		\
	  tokens_print.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = minishell
JULIEN_BIN = ms_julien
GUILHEM_BIN = ms_guilhem

INCLUDES = -Iinclude/
LIB = libft.a

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ -fsanitize=address

all: ${NAME}

${LIB}:
	cd libft/ && make && cp -v libft.a ../

$(NAME): ${LIB} $(OBJ) src/main.o
	$(CC) ${FLAGS} src/main.o $(OBJ) -L. -lft -o $(NAME) -fsanitize=address

$(JULIEN_BIN): ${LIB} $(OBJ) src/julien_main.o
	$(CC) ${FLAGS} src/julien_main.o $(OBJ) -L. -lft -o $(JULIEN_BIN) -fsanitize=address

$(GUILHEM_BIN): ${LIB} $(OBJ) src/guilhem_main.o
	$(CC) ${FLAGS} src/guilhem_main.o $(OBJ) -L. -lft -o $(GUILHEM_BIN) -fsanitize=address

re: fclean all

clean:
	cd libft/ && make clean
	${RM} src/julien_main.o
	${RM} src/guilhem_main.o
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME} $(JULIEN_BIN) $(GUILHEM_BIN)
	${RM} ${LIB}

.PHONY: all re clean fclean
