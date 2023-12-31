SRC=ft_printf.c \
	format.c \
	put_util.c \
	printer.c \
	printer_2.c \
	conversion.c \
	util.c \
	util2.c
OBJ=$(SRC:.c=.o)
TEST=test.c
NAME=libftprintf.a
HEADER=ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	cc -c -Wall -Wextra -Werror $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
