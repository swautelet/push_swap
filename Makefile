FILES = src/push_swap.c \
	src/error.c \
	src/sortlittle.c
OBJECT = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Werror -Wall -Wextra 
NAME = push_swap
HEADER = src/push_swap.h
LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJECT)
	make bonus -C libft
	$(CC) $(CFLAGS) $(OBJECT) $(LIB) -o $(NAME)

.o : .c
	$(CC) $(CFLAGS) $? -o $(?:.c=.o)

clean :
	rm -f $(OBJECT)

fclean : clean 
	rm -f $(NAME)

re : fclean all

save : 
	git add $(FILES) $(HEADER) Makefile libft/
	git commit -m autosave
	git push https://github.com/swautelet/push_swap.git

.phony : save re fclean clean all