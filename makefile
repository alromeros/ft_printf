CC=gcc
CFLAGS=-Wall -Werror -Wextra
OBJ=char_mgmt.o format_checker.o flag_checker.o ft_printf_utils.o ft_printf.o ft_putnbr.o \
	memory_mgmt.o nbr_mgmt.o str_mgmt.o
SRC = $(OBJ:.o=.c)

all: $(SRC) main.c printf.h libft.h
	$(CC) $(CFLAGS) $(SRC) main.c

lib: $(OBJ) printf.h libft.h
	ar rcs libftprintf.a $(OBJ)
clean:
	rm -rf *.o printf *.a *.out
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<