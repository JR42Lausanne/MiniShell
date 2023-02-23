# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:44:06 by jlaiti            #+#    #+#              #
#    Updated: 2023/01/17 15:52:28 by jlaiti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_strlen.c			\
	ft_isalnum.c			\
	ft_isalpha.c			\
	ft_isascii.c			\
	ft_isdigit.c			\
	ft_isprint.c			\
	ft_strchr.c				\
	ft_strrchr.c			\
	ft_strlen.c				\
	ft_tolower.c			\
	ft_toupper.c			\
	ft_strncmp.c			\
	ft_atoi.c				\
	ft_strdup.c				\
	ft_memset.c				\
	ft_bzero.c				\
	ft_memcpy.c				\
	ft_memmove.c			\
	ft_putchar_fd.c			\
	ft_putstr_fd.c			\
	ft_putendl_fd.c			\
	ft_putnbr_fd.c			\
	ft_strlcpy.c			\
	ft_strlcat.c			\
	ft_memchr.c				\
	ft_memcmp.c				\
	ft_strnstr.c			\
	ft_calloc.c				\
	ft_strjoin.c			\
	ft_substr.c				\
	ft_strtrim.c			\
	ft_itoa.c				\
	ft_striteri.c			\
	ft_strmapi.c			\
	ft_split.c				\
	ft_check_args.c			\
	ft_number.c				\
	ft_printf.c				\
	ft_putchar.c			\
	ft_unsigned_int.c		\
	ft_char.c				\
	ft_hexa.c				\
	ft_pointer.c			\
	ft_string.c				\
	get_next_line.c			\
	get_next_line_utils.c	\
	ft_lstnew_bonus.c 		\
	ft_lstadd_front_bonus.c	\
	ft_lstsize_bonus.c		\
	ft_lstlast_bonus.c		\
	ft_lstadd_back_bonus.c	\
	ft_lstdelone_bonus.c	\
	ft_lstclear_bonus.c		\
	ft_lstiter_bonus.c		\

NAME = libft.a

OBJS_SRCS = $(SRCS:.c=.o)

OBJS_BSRCS = $(B_SRCS:.c=.o)  

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
CC = gcc $(CFLAGS)

$(NAME) : $(OBJS_SRCS)
	ar rcs $(NAME) $(OBJS_SRCS)


%.o : %.c
	$(CC) -o $@ -c $< -I.

all : $(NAME)

clean :
	rm -rf $(OBJS_SRCS) $(OBJS_BSRCS)

fclean : clean
	rm -f $(NAME)

re : fclean all
	
bonus : $(OBJS_SRCS) $(OBJS_BSRCS)
	ar rcs $(NAME) $(OBJS_SRCS) $(OBJS_BSRCS)

.PHONY: all clean fclean re bonus
