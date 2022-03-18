FILES = src/push_swap.c \
	src/error.c \
	src/sortlittle.c \
	src/swap.c \
	src/push.c \
	src/rotate.c \
	src/rerotate.c \
	src/copy_and_try.c \
	src/sortbig.c
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
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

save : 
	make fclean -C libft
	git add $(FILES) $(HEADER) Makefile libft/
	git commit -m autosave
	git push https://github.com/swautelet/push_swap.git

.phony : save re fclean clean all
