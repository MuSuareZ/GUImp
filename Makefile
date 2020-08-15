# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 10:37:05 by krusthol          #+#    #+#              #
#    Updated: 2020/08/15 17:06:15 by msuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = guimp
SRC = main.c window.c
OBJ = $(subst .c,.o,$(SRC))
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBS = -Llibft -lft -lSDL2 -lSDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(LIBFT) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re
