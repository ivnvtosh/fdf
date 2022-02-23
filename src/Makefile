# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 17:33:31 by ccamie            #+#    #+#              #
#    Updated: 2022/02/23 17:33:34 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../fdf
HEADER		=	   fdf.h

LIBFT		=	../libft/libft.a
LIBGNL		=	../libgnl/libgnl.a
LIBMLX		=	../libmlx/libmlx.a

SRCS		=	background.c			\
				check_file.c			\
				check_map.c				\
				check_on_the_screen.c	\
				color.c					\
				display_screen.c		\
				event.c					\
				fdf.c					\
				get_map_color.c			\
				get_map_height.c		\
				get_map_size.c			\
				iso.c					\
				keyboard.c				\
				main.c					\
				parse_frame.c			\
				parse_map.c				\
				parse_mlx.c				\
				parse_var.c				\
				parser.c				\
				split_free.c			\
				split_list.c			\
				terminate.c				\
				vector.c				\
				write.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(LIBGNL) $(LIBMLX) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) 

%.o			:	%.c $(HEADER) $(LIBFT) $(LIBGNL) $(LIBMLX)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
