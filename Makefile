# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foctavia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:47:59 by foctavia          #+#    #+#              #
#    Updated: 2022/05/09 16:49:52 by foctavia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c\
		ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c\
		ft_bzero.c\
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_atoi.c ft_itoa.c\
		ft_calloc.c\
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c
				
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
