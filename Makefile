# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkwon <rkwon@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/03 17:05:13 by rkwon             #+#    #+#              #
#    Updated: 2018/05/03 17:05:47 by rkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@ar -q libft.a *.o
	@gcc -Wall -Wextra -Werror -g -L. -lft *.c -o GNL

clean:
	@rm -rf *.o *.a

fclean: clean
	@rm -rf fillit

re: fclean all

