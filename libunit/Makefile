RM      = rm -rf
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar -rcs

SRC     = utest_run.c utest_fork_handlers.c helpers.c
SRC_TOT = $(addprefix framework/, $(SRC))
OBJ     = $(SRC_TOT:.c=.o)
INCLUDE = framework

NAME    = libunit.a

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CLFAGS)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

test: $(NAME)
	@cd tests && make "TEST_OBJ=$(OBJ)" && make test

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
