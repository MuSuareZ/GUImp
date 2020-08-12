# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 18:38:32 by krusthol          #+#    #+#              #
#    Updated: 2019/11/03 11:27:09 by krusthol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_isdigit.c ft_isalpha.c ft_bzero.c ft_isalnum.c \
	  ft_isprint.c ft_isascii.c ft_memalloc.c ft_memchr.c ft_memdel.c \
	  ft_memccpy.c ft_memcmp.c ft_strcat.c ft_memcpy.c ft_strclr.c \
	  ft_strchr.c ft_strdel.c ft_strcmp.c ft_memmove.c ft_strcpy.c \
	  ft_striter.c ft_striteri.c ft_strdup.c ft_strjoin.c ft_strlen.c \
	  ft_strlcat.c ft_strmap.c ft_itoa.c ft_strmapi.c ft_strncmp.c \
	  ft_strnequ.c ft_memset.c ft_strncpy.c ft_strnew.c ft_strequ.c \
	  ft_strrchr.c ft_strncat.c ft_tolower.c ft_strsub.c ft_toupper.c \
	  ft_strnstr.c ft_strtrim.c ft_strstr.c ft_strsplit.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_words.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_edgeint.c \
	  ft_putlst.c ft_lstadd_back.c ft_lstsize.c ft_isspace.c
OBJ = $(subst .c,.o,$(SRC))
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
