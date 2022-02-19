
NAME		=	../fdf
HEADER		=	   fdf.h

LIBFT		=	../libft/libft.a
LIBGNL		=	../libgnl/libgnl.a
LIBST		=	../libmlx/libmlx.a

SRCS		=	main.c			\
				# background.c	\
				# display_screen.c\
				# terminate.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(LIBGNL) $(MINILIBX) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) 

%.o			:	%.c $(HEADER) $(LIBFT) $(LIBGNL) $(MINILIBX)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
