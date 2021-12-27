# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:45:41 by ccamie            #+#    #+#              #
#    Updated: 2021/10/18 15:45:43 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	printf.h

LIBFT		=	../libft/libft.a

SRCS		=	print_char.c					\
				print_decimal.c					\
				print_hexadecimal_lowercase.c	\
				print_hexadecimal_uppercase.c	\
				print_number.c					\
				print_part.c					\
				print_pointer.c					\
				print_string.c					\
				print_unsigned_decimal.c		\
				printf_utils.c					\
				ft_printf.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJS)
				cp $(LIBFT) $(NAME) 
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT)	:
				make -C libft
				make -C libft clean

$(OBJS)		:	%.o	: %.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
