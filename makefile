# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alromero <alromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 19:16:26 by alromero          #+#    #+#              #
#    Updated: 2019/12/20 19:23:18 by alromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC=gcc
CFLAGS=-Wall -Werror -Wextra

NAME = libftprintf.a
SRC=char_mgmt.c format_checker.c flag_checker.c ft_printf_utils.c ft_printf.c \
	memory_mgmt.c nbr_mgmt.c str_mgmt.c hex_mgmt.c unsigned_mgmt.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<