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

NAME		=		fdf
HEADER		=	src/fdf.h

LIBFT		=	libft/libft.a
MINILIBX	=	minilibx/libmlx.a

GNL			=	get_next_line/get_next_line_utils.c	\
				get_next_line/get_next_line.c

SRCS		=	src/background.c	\
				src/draw.c			\
				src/event.c			\
				src/fdf.c			\
				src/key_pressed.c	\
				src/main.c			\
				src/parser.c		\
				src/preprocessing.c	\
				src/terminate.c		\
				src/window.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o) $(GNL:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(MINILIBX) $(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(MINILIBX) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) 

$(LIBFT)	:
				make -C libft bonus
				make -C libft clean

$(MINILIBX)	:
				make -C minilibx

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
