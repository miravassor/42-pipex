# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 10:40:46 by avassor           #+#    #+#              #
#    Updated: 2022/12/26 15:12:14 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPEX	= pipex
NAME	= $(PIPEX)

CC		=	cc
CFLAGS 	=	-Wall -Wextra -Werror
INC		=	-I ./inc/

LIBFT_PATH	 =	libft/
LIBFT_NAME	 =	libft.a
LIBFT		 =	$(LIBFT_PATH)$(LIBFT_NAME)

SRC_PATH =	src/
OBJ_PATH =	obj/

SRC =				pipex.c			\
					p_rror.c		\
					p_clean.c		\
					p_parse.c		\
					p_utils_1.c		\
					p_utils_2.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = ${SRCS:${SRC_PATH}%.c=${OBJ_PATH}%.o}

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c ./inc/pipex.h
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(LIBFT):
	$(MAKE) -sC $(LIBFT_PATH)

all: $(NAME)


clean:
	rm -rdf $(OBJ_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f ".ppxtmp"
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
