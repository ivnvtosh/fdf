# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 19:37:03 by ccamie            #+#    #+#              #
#    Updated: 2022/02/23 19:37:07 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../fdf
HEADER		=	   fdf.h

LIBFT		=	../libft/libft.a
LIBGNL		=	../libgnl/libgnl.a
LIBMLX		=	../libmlx/libmlx.a

SRCS		=	2d_bonus.c					\
				3d_bonus.c					\
				background_bonus.c			\
				check_file_bonus.c			\
				check_map_bonus.c			\
				check_on_the_screen_bonus.c	\
				color_bonus.c				\
				display_screen_bonus.c		\
				event_bonus.c				\
				fdf_bonus.c					\
				get_map_color_my_bonus.c	\
				get_map_color_bonus.c		\
				get_map_height_bonus.c		\
				get_map_size_bonus.c		\
				keyboard_bonus.c			\
				main_bonus.c				\
				mode_color_bonus.c			\
				mouse_bonus.c				\
				parse_frame_bonus.c			\
				parse_map_bonus.c			\
				parse_mlx_bonus.c			\
				parse_var_bonus.c			\
				parser_bonus.c				\
				split_free_bonus.c			\
				split_list_bonus.c			\
				terminate_bonus.c			\
				vector_bonus.c				\
				write_bonus.c

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
