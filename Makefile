CC= gcc
FLAGS= -Wall -Werror -Wextra
NAME= push_swap
SRCS= push_swap.c \
	arg_check.c \
	operation_1.c \
	operation_2.c \
	operation_3.c \
	stack_big.c \
	stack_small.c \
	utils_1.c \
	utils_2.c \

OBJS= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	gcc  $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
