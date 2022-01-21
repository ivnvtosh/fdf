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

NAME		=	../fdf
HEADER		=	   fdf.h

LIBFT		=	../libft/libft.a
MINILIBX	=	../minilibx/libmlx.a

GNL			=	../get_next_line/get_next_line_utils.c	\
				../get_next_line/get_next_line.c
HEADER_GNL	=	../get_next_line/get_next_line.h

SRCS		=	2d.c			\
				background.c	\
				display_screen.c\
				event.c			\
				fdf.c			\
				keyboard.c		\
				main.c			\
				mouse.c			\
				parser.c		\
				terminate.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o) $(GNL:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(MINILIBX) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) 

%.o			:	%.c $(HEADER) $(HEADER_GNL) $(LIBFT) $(MINILIBX)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
