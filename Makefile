# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 12:21:01 by jreynaer          #+#    #+#              #
#    Updated: 2019/01/09 16:56:37 by hde-ghel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJ = *.o
SRC = *.c Libft/libft.a
FLAGS = -wall -wextra #-werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L minilibx/ -lmlx -lm -L/usr/lib64/X11 -lX11 -lXext -L/usr/lib64
	##-framework OpenGL -framework Appkit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
