# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:14:10 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/21 17:20:50 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD 

RM = rm -f

INCS = -I includes -I libft/includes

NAME = philo_bonus

ALLLIB = libft/libft.a

all: $(NAME)

$(NAME) : $(OBJS) $(ALLLIB)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) -o $(NAME) $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

libft/libft.a :
	$(MAKE) -C libft all

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re