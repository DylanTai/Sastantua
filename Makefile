# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 14:32:46 by minhnguy          #+#    #+#              #
#    Updated: 2020/01/16 12:43:20 by dtai             ###   ########.fr        #
#    Updated: 2019/08/26 19:42:23 by dtai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sastantua
FLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
SRCS = \
srcs/sastantua.c \
srcs/ft_putchar.c
OBJECTS = \
sastantua.o \
ft_putchar.o

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME) -I $(INCLUDES)

$(OBJECTS).o:
	gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
