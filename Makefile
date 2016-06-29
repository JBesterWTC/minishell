# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbester <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/21 12:01:27 by jbester           #+#    #+#              #
#    Updated: 2016/06/27 09:07:08 by jbester          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

NAME2 = libft/libft.a

SRCS = main.c command.c flag.c

DIR = "libft"

FLAGS = -Wall -Werror -Wextra

$(NAME):
	make -C $(DIR)
	gcc -o $(NAME) $(SRCS) $(NAME2) $(FLAGS)

all: $(NAME)

clean:
	make clean -C $(DIR)

fclean:
	make fclean -C $(DIR)
	rm -f minishell

re: fclean all
