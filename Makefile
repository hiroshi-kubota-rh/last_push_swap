CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME		:= push_swap

SRSC =	src/main.c \
		src/error/error.c \
		src/error/flash_all_struct.c \
		src/error/flash_stack.c \
		src/input/check_argc.c \
		src/input/check_num_array.c \
		src/input/check_sorted.c \
		src/input/coordinate_compression.c \
		src/input/fill_stack_a.c \
		src/input/make_stack.c \
		src/input/set_num_array.c \
		src/input/set_num_array_len.c \
		src/rules/push.c \
		src/rules/revrotate.c \
		src/rules/rotate.c \
		src/rules/swap.c \
		src/six-less-sort/input_2.c \
		src/six-less-sort/input_3.c \
		src/six-less-sort/input_4.c \
		src/six-less-sort/input_5.c \
		src/six-less-sort/six_less_sort.c \
		src/sort/alignment_stack_a.c \
		src/sort/biggest_element.c \
		src/sort/execute_insert.c \
		src/sort/permu.c \
		src/sort/push_not_sorted_to_b.c \
		src/sort/set_sorted.c \
		src/sort/sort.c \
		src/utils/ft_atoi.c \
		src/utils/ft_isint.c \
		src/utils/ft_memcpy.c \
		src/utils/ft_node_addback.c \
		src/utils/ft_node_len.c \
		src/utils/ft_node_new.c \
       	src/utils/ft_split.c \
		src/utils/ft_strlen.c

OBJS := $(SRSC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERPATH)
	$(CC) $(CFLAGS) -c -I./include -o $@ $<

PHONY: all
all: $(NAME)

PHONY: clean
clean:
	@echo "$(_RED)Removing object files....$(_END)"
	@rm -f $(OBJS)

PHONY: fclean
fclean:
	@echo "$(_RED)Removing object files and program....$(_END)"
	@rm	-f $(NAME)
	@rm -f $(OBJS)

PHONY: re
re: fclean all
