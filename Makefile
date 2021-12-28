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

NAME		=	fdf

LIBFT		=	libft/libft.a
FT_PRINTF	=	ft-printf/libftprintf.a
LIBMLX		=	minilibx_macos/libmlx.a

SRCS		=	get-next-line/get_next_line_utils.c	\
				get-next-line/get_next_line.c		\
				program/main.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(FT_PRINTF) $(LIBMLX) $(OBJS)
				$(CC) $(CFLAGS) $(FT_PRINTF) $(LIBMLX) $(OBJS) -framework OpenGL -framework AppKit -o $(NAME) 

$(LIBFT)	:
				make -C libft
				make -C libft clean
	
$(FT_PRINTF):
				make -C ft-printf
				make -C ft-printf clean

$(LIBMLX)	:
				make -C minilibx_macos

$(OBJS)		:	%.o	: %.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

allclean	:	clean
				$(RM) $(NAME) $(LIBFT) $(FT_PRINTF)

re			:	fclean all

allre		:	allclean all

.PHONY		:	all clean fclean re allclean allre
