
NAME		=	../fdf
HEADER		=	   fdf.h

LIBFT		=	../libft/libft.a
LIBGNL		=	../libgnl/libgnl.a
LIBMLX		=	../libmlx/libmlx.a

SRCS		=	2d.c					\
				3d.c					\
				background.c			\
				check_file.c			\
				check_map.c				\
				check_on_the_screen.c	\
				color.c					\
				display_screen.c		\
				event.c					\
				fdf.c					\
				get_map_color_my.c		\
				get_map_color.c			\
				get_map_height.c		\
				get_map_size.c			\
				keyboard.c				\
				main.c					\
				mouse.c					\
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
