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

# F = -Wall -Wextra -Werror

NAME_1 = push_swap

NAME_2 = checker
 
TEST = 5 8 6 3 1 2

OBJECT_1 = push_swap.o list_push_front.o ps_error.o

OBJECT_2 = checker.o

.PHONY: all clean fclean re bug debug

all: $(NAME_1) $(NAME_2)
	@make -C libft/
	@make -C ft_printf/

$(NAME_1): $(OBJECT_1)
		@make -C libft/
		@make -C ft_printf/
		$(GCC) $(F) -o $(NAME_1) $(OBJECT_1) -I minilibx_macos/libmlx.a libft/libft.a ft_printf/libftprintf.a

$(NAME_2): $(OBJECT_2)
		@make -C libft/
		@make -C ft_printf/
		$(GCC) $(F) -o $(NAME_2) $(OBJECT_2) -I minilibx_macos/libmlx.a libft/libft.a ft_printf/libftprintf.a

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	rm -rf $(OBJECT_1) $(OBJECT_2)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME_1) $(NAME_2) a.out

re: fclean all

r: all
	./$(NAME_1) $(TEST)

c: all
	./$(NAME_2) $(TEST)

bug:
	gcc -g $(F) -o $(NAME_1) push_swap.c libft/libft.a ft_printf/libftprintf.a 

debug: bug
	lldb -- ./a.out $(TEST)

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
