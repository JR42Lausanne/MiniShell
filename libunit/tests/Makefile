RM      = rm -rf
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar -rcs

SRC_MINISHELL = 00_minishell_launcher.c  \
				   01_basic_test.c \
				   02_null_test.c \
				   03_segv_test.c
SRC_MINISHELL_DIR = $(addprefix minishell/, $(SRC_MINISHELL))

SRC     = main.c \
		  $(SRC_MINISHELL_DIR)
OBJ     = $(SRC:.c=.o)
INCLUDE = ../framework

NAME    = unittests

TEST_OBJ_TOT = $(addprefix ../, $(TEST_OBJ))

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CLFAGS)

$(NAME): $(OBJ) $(TEST_OBJ_TOT)
	$(CC) -o $(NAME) $(CFLAGS) -I$(INCLUDE) $(OBJ) $(TEST_OBJ_TOT) 
	@echo "TEST COMPILATION DONE"

test: $(NAME)
	@echo "---------------UNIT TESTER---------------"
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: re all clean fclean
