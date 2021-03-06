# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 12:21:01 by jreynaer          #+#    #+#              #
#    Updated: 2019/07/07 00:21:04 by hde-ghel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./main.c ./ft_mlx.c ./ft_read.c ./ft_traceseg.c ./hook.c ./inits.c\
	./key_press.c ./map.c ./menu.c ./projections.c ./rotate.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./Libft/libft.a

FRAMEWORK = -framework OpenGL -framework Appkit


$(NAME):
	@make -C ./Libft/
	@echo 'Libft compilation : OK'
	@gcc $(CFLAGS) -o $(NAME) $(SRC) \
		$(LIBFT) -L minilibx_macos/ -lmlx $(FRAMEWORK)
	@echo 'fdf compilation : OK'

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo 'fdf clean : OK'
	@make clean -C ./Libft/
	@echo 'Libft clean : OK'

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./Libft/

re: fclean all

.PHONY: all clean fclean re
