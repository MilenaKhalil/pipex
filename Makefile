# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <mikhalil@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/06 21:11:14 by mikhalil      #+#    #+#                  #
#    Updated: 2023/05/20 21:31:19 by mikhalil      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC =	pipex.c \
		childs.c \
		exits.c \
		main.c

SRC_BONUS =	pipex.c \
			childs_bonus.c \
			exits.c \
			main_bonus.c

LIBFT = ./libft/libft.a

OBJ_REG = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


ifdef WITH_BONUS
OBJ = $(SRC_BONUS:.c=.o)
HEADER = pipex_bonus.h
NAME = pipex_bonus
else
OBJ = $(OBJ_REG)
HEADER = pipex.h
NAME = pipex
endif

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I ./

CC = cc

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft
	
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ_REG) $(OBJ_BONUS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all re fclean clean bonus
