# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <mikhalil@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/06 21:11:14 by mikhalil      #+#    #+#                  #
#    Updated: 2023/05/14 17:44:28 by mikhalil      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC =	pipex.c \
		childs.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra #-g3

NAME = pipex

INCLUDE = -I ./

CC = cc

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft
	
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all re fclean clean
