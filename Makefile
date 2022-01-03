# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 14:52:07 by dclark            #+#    #+#              #
#    Updated: 2022/01/03 15:43:08 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/add_lst_bck2.c \
			srcs/print_lst.c \
			srcs/check_error_quotes.c \
			srcs/parsing2.c \
			srcs/expension.c \
			srcs/quotes_exp.c \
			srcs/tab_to_list.c \
			srcs/ft_strjoin.c \
			srcs/ft_strljoin.c \
			srcs/ft_separ2.c \
			srcs/ft_strlen.c \
			srcs/ft_isalpha.c \
			srcs/ft_echo.c \
			main.c

HEADER	=includes/

NAME	= minishell

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER)

CC		= gcc

#%.o: %.c
#	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean
	make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

.PHONY: all clean fclean re
