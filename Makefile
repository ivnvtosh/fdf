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

.PHONY		:	all clean fclean re bonus rebonus libft libgnl libmlx

all			:	libft libgnl libmlx
				make -C src all

bonus		:	libft libgnl libmlx
				make -C src_bonus all

libft		:
				make -C libft bonus

libgnl		:
				make -C libgnl

libmlx	:
				make -C libmlx

clean		:
				make -C src clean
				make -C src_bonus clean
				make -C libft clean
				make -C libgnl clean
				make -C libmlx clean

fclean		:
				make -C src fclean
				make -C src_bonus fclean
				make -C libft fclean
				make -C libgnl fclean
				make -C libmlx fclean
				
re			:	fclean all

rebonus		:	fclean bonus
