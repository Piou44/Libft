# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:52:41 by fhuang            #+#    #+#              #
#    Updated: 2016/05/18 17:31:21 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRC = ft_memset.c	\
	  ft_bzero.c	\
	  ft_memcpy.c	\
	  ft_memccpy.c	\
	  ft_memmove.c	\
	  ft_memchr.c	\
	  ft_memcmp.c	\
	  ft_strlen.c	\
	  ft_strdup.c	\
	  ft_strndup.c	\
	  ft_strcpy.c	\
	  ft_strncpy.c	\
	  ft_strcat.c	\
	  ft_strncat.c	\
	  ft_strlcat.c	\
	  ft_strchr.c	\
	  ft_strrchr.c	\
	  ft_strstr.c	\
	  ft_strnstr.c	\
	  ft_strcmp.c	\
	  ft_strncmp.c	\
	  ft_atoi.c		\
	  ft_isalpha.c	\
	  ft_isdigit.c	\
	  ft_isalnum.c	\
	  ft_isascii.c	\
	  ft_isspace.c	\
	  ft_isprint.c	\
	  ft_isascii.c	\
	  ft_toupper.c	\
	  ft_tolower.c	\
	  ft_memalloc.c	\
	  ft_realloc.c	\
	  ft_memdel.c	\
	  ft_strnew.c	\
	  ft_strdel.c	\
	  ft_strclr.c	\
	  ft_striter.c	\
	  ft_striteri.c	\
	  ft_strmap.c	\
	  ft_strmapi.c	\
	  ft_strequ.c	\
	  ft_strnequ.c	\
	  ft_strsub.c	\
	  ft_strjoin.c	\
	  ft_tablen.c	\
	  ft_tabatoi.c	\
	  ft_tabfree.c	\
	  ft_trim_c.c	\
	  ft_strtrim.c	\
	  ft_power_pos.c\
	  ft_itoa.c		\
	  ft_putchar.c	\
	  ft_putstr.c	\
	  ft_putstrcol.c\
	  ft_putendl.c	\
	  ft_putendlcol.c\
	  ft_putnbrendl.c\
	  ft_putnbr.c	\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_nbrlen.c	\
	  ft_strsplit.c	\
	  ft_lstnew.c	\
	  ft_lstdelone.c\
	  ft_lstdel.c	\
	  ft_lstadd.c	\
	  ft_lstaddend.c\
	  ft_lstlen.c	\
	  ft_lstiter.c	\
	  ft_lstmap.c	\
	  ft_dynam_append.c\
	  ft_dynam_destroy.c\
	  ft_dynam_new.c\
	  ft_dynam_trim.c\
	  get_next_line.c\

CFLAGS = -c -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all : $(NAME)

$(NAME): $(OBJ)
	@echo "----------------------------LIBFT----------------------------"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o : %.c
	@echo "\033[32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
