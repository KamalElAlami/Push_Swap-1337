# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:30:49 by kael-ala          #+#    #+#              #
#    Updated: 2024/05/06 02:08:41 by kael-ala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

P_FILES = ./ft_printf/ft_printf.c ./ft_printf/printtools.c ./ft_printf/printtoolss.c 

M_FILES = push_swap.c args_parsing.c parsing_utilities.c stack_inits.c helpers.c stack_operations.c utilities.c stack_sorting.c stack_operations_aio.c

B_FILES = ./Bonus/push_swap_bonus.c ./Bonus/args_parsing_bonus.c ./Bonus/parsing_utilities_bonus.c ./Bonus/stack_inits_bonus.c ./Bonus/helpers_bonus.c ./Bonus/stack_operations_bonus.c ./Bonus/utilities_bonus.c ./Bonus/stack_operations_aio_bonus.c ./Bonus/get_next_line_bonus.c ./Bonus/check_instructions_bonus.c

INCS = ./includes/ft_printf.h ./includes/libft.h

libft = ./Libft/libft.a

P_OBJ = $(P_FILES:.c=.o)
M_OBJ = $(M_FILES:.c=.o)
B_OBJ = $(B_FILES:.c=.o)

all : $(NAME)

$(NAME) :  $(P_OBJ) $(M_OBJ) $(libft)
	$(CC) $(FLAGS) $(libft) $^ -o $(NAME)

bonus : $(BNAME) $(libft)

$(BNAME) : $(P_OBJ) $(B_OBJ) $(libft)
	$(CC) $(FLAGS) $^ $(libft) -o $(BNAME)

$(B_OBJ) : ./includes/push_swap_bonus.h
$(M_OBJ) : ./includes/push_swap.h

%.o : %.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@
$(libft) :
	make -C ./Libft
	make -C ./Libft bonus
clean:
	$(RM) $(P_OBJ) $(M_OBJ) $(B_OBJ)
	make -C ./Libft clean
fclean: clean
	$(RM) $(P_OBJ) $(M_OBJ) $(B_OBJ) $(NAME) $(BNAME)
	make -C ./Libft fclean
re: fclean all
