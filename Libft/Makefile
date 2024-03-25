# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:14:53 by kael-ala          #+#    #+#              #
#    Updated: 2023/12/01 14:26:10 by kael-ala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = ft_striteri.c ft_memcmp.c  ft_bzero.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c \
	ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_strtrim.c ft_strjoin.c ft_strdup.c \
	ft_calloc.c  ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memchr.c ft_memset.c ft_memcpy.c \
	ft_strlen.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c ft_atoi.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c \
	ft_tolower.c ft_toupper.c ft_memmove.c ft_split.c \
	ft_substr.c

B_FILES = ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

OBJ = $(FILES:.c=.o)

B_OBJ = $(B_FILES:.c=.o)

AR = ar rc

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(B_OBJ)
	$(AR) $(NAME) $(B_OBJ)

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean 