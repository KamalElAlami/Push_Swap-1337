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

L_FILES = ./Libft/ft_striteri.c ./Libft/ft_memcmp.c  ./Libft/ft_bzero.c ./Libft/ft_putnbr_fd.c ./Libft/ft_strmapi.c ./Libft/ft_itoa.c \
	./Libft/ft_putendl_fd.c ./Libft/ft_putchar_fd.c ./Libft/ft_putstr_fd.c ./Libft/ft_strtrim.c ./Libft/ft_strjoin.c ./Libft/ft_strdup.c \
	./Libft/ft_calloc.c  ./Libft/ft_isalnum.c ./Libft/ft_isalpha.c \
	./Libft/ft_isascii.c ./Libft/ft_isdigit.c ./Libft/ft_isprint.c \
	./Libft/ft_memchr.c ./Libft/ft_memset.c ./Libft/ft_memcpy.c \
	./Libft/ft_strlen.c ./Libft/ft_strncmp.c ./Libft/ft_strlcat.c ./Libft/ft_strlcpy.c ./Libft/ft_atoi.c \
	./Libft/ft_strchr.c ./Libft/ft_strrchr.c ./Libft/ft_strnstr.c \
	./Libft/ft_tolower.c ./Libft/ft_toupper.c ./Libft/ft_memmove.c ./Libft/ft_split.c \
	./Libft/ft_substr.c ./Libft/ft_lstadd_front_bonus.c ./Libft/ft_lstnew_bonus.c ./Libft/ft_lstsize_bonus.c ./Libft/ft_lstlast_bonus.c ./Libft/ft_lstadd_back_bonus.c ./Libft/ft_lstdelone_bonus.c ./Libft/ft_lstclear_bonus.c ./Libft/ft_lstiter_bonus.c

P_FILES = ./ft_printf/ft_printf.c ./ft_printf/printtools.c ./ft_printf/printtoolss.c 

M_FILES = push_swap.c args_parsing.c parsing_utilities.c stack_inits.c helpers.c stack_operations.c utilities.c stack_sorting.c stack_operations_aio.c

B_FILES = ./Bonus/push_swap_bonus.c ./Bonus/args_parsing_bonus.c ./Bonus/parsing_utilities_bonus.c ./Bonus/stack_inits_bonus.c ./Bonus/helpers_bonus.c ./Bonus/stack_operations_bonus.c ./Bonus/utilities_bonus.c ./Bonus/stack_operations_aio_bonus.c ./Bonus/get_next_line_bonus.c ./Bonus/check_instructions_bonus.c

INCS = ./includes/ft_printf.h ./includes/push_swap.h ./includes/libft.h ./includes/push_swap_bonus.h

L_OBJ = $(L_FILES:.c=.o)
P_OBJ = $(P_FILES:.c=.o)
M_OBJ = $(M_FILES:.c=.o)
B_OBJ = $(B_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(L_OBJ) $(P_OBJ) $(M_OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME)

bonus : $(BNAME)

$(BNAME) : $(L_OBJ) $(P_OBJ) $(B_OBJ)
	$(CC) $(FLAGS) $^ -o $(BNAME)

%.o : %.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(L_OBJ) $(P_OBJ) $(M_OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(L_OBJ) $(P_OBJ) $(M_OBJ) $(B_OBJ) $(NAME) $(BNAME)

re: fclean all
