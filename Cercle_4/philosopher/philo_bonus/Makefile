# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:14:10 by bsavinel          #+#    #+#              #
#    Updated: 2022/03/01 14:19:47 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -pthread

RM = rm -f

INCS = -I includes

NAME = philo_bonus

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re