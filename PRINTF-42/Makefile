# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faacar <faacar@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 11:43:27 by faacar            #+#    #+#              #
#    Updated: 2023/07/17 15:37:35 by faacar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

LIB1	= ar -rcs
LIB2	= ranlib

SRCS_MAND	=	ft_printf.c \
				ft_printf_utils.c

OBJS_MAND	=	${SRCS_MAND:.c=.o}

$(NAME)	:	$(OBJS_MAND)
			$(LIB1) $(NAME) $(OBJS_MAND)
			$(LIB2) $(NAME)

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS_MAND)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
