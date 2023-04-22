# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 19:44:36 by yoamzil           #+#    #+#              #
#    Updated: 2023/04/22 14:28:46 by yoamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=   cc 
CFLAGS		=   -Wall -Wextra -Werror

SRC			=   get_next_line/get_next_line.c \
                          get_next_line/get_next_line_utils.c \
                          libft/ft_atoi.c \
                          libft/ft_bzero.c \
                          libft/ft_calloc.c \
                          libft/ft_isalnum.c \
                          libft/ft_isalpha.c \
                          libft/ft_isascii.c \
                          libft/ft_isdigit.c \
                          libft/ft_isprint.c \
                          libft/ft_itoa.c \
                          libft/ft_memchr.c \
                          libft/ft_memcmp.c \
                          libft/ft_memcpy.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_split.c \
                          libft/ft_strchr.c \
                          libft/ft_strdup.c \
                          libft/ft_striteri.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_strmapi.c \
                          libft/ft_strncmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_strrchr.c \
                          libft/ft_strtrim.c \
                          libft/ft_substr.c \
                          libft/ft_tolower.c \
                          libft/ft_toupper.c \
						  
PSP			= so_long.c

OBJ			= $(SRC:.c=.o)
OBJ_MAIN	= $(PSP:.c=.o)

RM			=   rm -f

all : $(NAME)
bonus: $(BONUS_NAME)

$(NAME) : $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_MAIN)
	make -C libft clean

fclean : clean
	$(RM) $(NAME)
	make -C libft fclean

re : fclean all
	make -C libft fclean re
