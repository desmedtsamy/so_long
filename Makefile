# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samy <samy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:51:56 by sde-smed          #+#    #+#              #
#    Updated: 2022/12/20 10:06:15 by samy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
LIB		=	-L ./libft -lft -L ./printf -lprintf -L ./get_next_line -lgnl -L /usr/local/include -lmlx -framework OpenGL -framework AppKit
SRCS	= 	src/mandatory/main.c\
			src/mandatory/utils.c\
			src/mandatory/check.c\
			src/mandatory/render.c\
			src/mandatory/check_access.c
			
LIBFT	= libft/
GNL	= get_next_line/
PRINTF	= printf/

WALL = WALL="./sprites/wall.xmp"

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM		= rm -rf

$(OBJ): $(SRC)
	@gcc $(FALGS) -c $(SRC) -D WALL=test

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(GNL)
	@make -C $(PRINTF)
	cc $(FLAGS) -g $(OBJS) $(LIB) -o $(NAME)
	
	
all: $(NAME)

clean:
	@make -C $(LIBFT) clean
	@make -C $(GNL) clean
	@make -C $(PRINTF) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT) fclean
	@make -C $(GNL) fclean
	@make -C $(PRINTF) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY:			all clean fclean re