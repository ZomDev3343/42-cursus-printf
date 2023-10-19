SRC=ft_printf.c precision.c format.c
OBJ=$(SRC:.c=.o)
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
