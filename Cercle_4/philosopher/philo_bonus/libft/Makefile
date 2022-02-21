# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 11:34:09 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/18 16:07:53 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_LIBFT = srcs/libft/
PATH_GNL = srcs/gnl/
PATH_PFT = srcs/pft/

SRCS_LIBFT	= 	$(addprefix $(PATH_LIBFT),	\
				ft_atoi.c					\
				ft_bzero.c					\
				ft_calloc.c					\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isdigit.c				\
				ft_isprint.c				\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_memcpy.c					\
				ft_memmove.c				\
				ft_memset.c					\
				ft_strchr.c					\
				ft_strdup.c					\
				ft_strjoin.c				\
				ft_strlcat.c				\
				ft_strlcpy.c				\
				ft_strlen.c					\
				ft_strncmp.c				\
				ft_strnstr.c				\
				ft_strrchr.c				\
				ft_tolower.c				\
				ft_toupper.c				\
				ft_strtrim.c				\
				ft_split.c					\
				ft_itoa.c					\
				ft_strmapi.c				\
				ft_striteri.c				\
				ft_putchar_fd.c				\
				ft_putstr_fd.c				\
				ft_putendl_fd.c				\
				ft_putnbr_fd.c				\
				ft_substr.c					\
				putnbr.c					\
				ft_lstnew.c					\
				ft_lstadd_front.c			\
				ft_lstsize.c				\
				ft_lstlast.c				\
				ft_lstadd_back.c			\
				ft_lstdelone.c				\
				ft_lstclear.c				\
				ft_lstiter.c				\
				ft_lstmap.c					\
				ft_putstr_unsigned.c		\
				abs.c)


SRCS_GNL	= 	$(addprefix $(PATH_GNL),	\
				get_next_line.c				\
				get_next_line_utils.c)

SRCS_PFT	=	$(addprefix $(PATH_PFT),	\
				ft_printf.c					\
				char.c						\
				decimal.c					\
				hexa_and_void.c				\
				struct_info.c				\
				unsign.c)

SRCS = $(SRCS_GNL) $(SRCS_LIBFT) $(SRCS_PFT)

OBJ	= $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

INCS = -I includes

RM = rm -f

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -MMD -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	
clean:
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

-include $(DEPS)

.PHONY: all clean fclean re