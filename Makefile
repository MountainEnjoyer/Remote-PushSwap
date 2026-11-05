# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 17:14:48 by zchauve           #+#    #+#              #
#    Updated: 2026/11/04 17:16:30 by zchauve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBDIR = libft
LIB = $(LIBDIR)/libft.a 

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	  push_swap_utils1.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
	cp $(LIB) .
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) libft.a -o $(NAME)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(RM) -f $(OBJ) libft.a

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
