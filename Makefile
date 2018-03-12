#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/03/05 22:47:28 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc

F = -Wall -Wextra -Werror

NAME_1 = push_swap

NAME_2 = checker

BONUS_TEST = -v -f -c

INCL = libft/libft.a  ### ft_printf/libftprintf.a

TEST = $(BONUS_TEST) 5 9 8 3 1

OBJECT =  	list_push_back.o \
			ps_error.o \
			print_stacks.o \
			make_ss.o \
			make_rr.o \
			make_rrr.o \
			pre_validate.o \
			init_var.o \
			read_flags.o \
			operation_push_back.o 

OBJECT_1 = 	$(OBJECT) \
			push_swap.o \
			sorting_logic.o \
			frst_sort_3_a.o \
			next_sort_3_a.o \
			next_sort_3_b.o \
			last_sort_3_b.o \
			add_function.o \
			optimization.o \
			backtrack_stack_a.o \
			print_operation.o \
			free_memory.o \
			opt_is_have_anti_oper.o \
			opt_is_double_node.o

OBJECT_2 = 	$(OBJECT) \
			checker.o \
			reading_commands.o 

.PHONY: all clean fclean re bug debug

all: $(NAME_1) $(NAME_2)
	@make -C libft/
	# @make -C ft_printf/

$(NAME_1): $(OBJECT_1)
		@make -C libft/
		# @make -C ft_printf/
		$(GCC) $(F) -o $(NAME_1) $(OBJECT_1) $(INCL)

$(NAME_2): $(OBJECT_2)
		@make -C libft/
		# @make -C ft_printf/
		$(GCC) $(F) -o $(NAME_2) $(OBJECT_2) $(INCL)

clean:
	@make clean -C libft/
	# @make clean -C ft_printf/
	rm -rf $(OBJECT_1) $(OBJECT_2) $(OBJECT)

fclean: clean
	@make fclean -C libft/
	# @make fclean -C ft_printf/
	@rm -rf $(NAME_1) $(NAME_2) a.out

re: fclean all

r: all
	./$(NAME_1) $(TEST)

c: all
	./$(NAME_2) $(TEST)

bug:
	gcc -g $(F) -o $(NAME_1) push_swap.c list_push_back.c ps_error.c print_stacks.c make_ss.c make_rr.c make_rrr.c pre_validate.c \
	init_var.c read_flags.c operation_push_back.c frst_sort_3_a.c next_sort_3_a.c \
	next_sort_3_b.c last_sort_3_b.c add_function.c optimization.c backtrack_stack_a.c \
	sorting_logic.c  print_operation.c $(INCL)

debug: bug
	gdb  --args $(NAME_1)   -v  12 11 10 9 8 7 6 5 4 3 2 1

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
