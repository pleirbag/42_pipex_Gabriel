# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 16:58:30 by gabpicci          #+#    #+#              #
#    Updated: 2024/03/01 20:16:41 by gabpicci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft.a

SRCS =	pipex.c pipex_utils.c ft_split.c extra_utils.c\

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) -L. -o $(NAME)

clean:
	@rm -f $(LIBFT)
	@rm -f $(BNS_OBJS)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
