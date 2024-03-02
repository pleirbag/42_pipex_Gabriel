# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 16:58:30 by gabpicci          #+#    #+#              #
#    Updated: 2024/03/02 18:04:46 by gabpicci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

SRCS =	pipex.c pipex_utils.c ft_split.c extra_utils.c\

RM = rm -fr

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) -L. -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(BNS_OBJS)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
