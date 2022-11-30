# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:51:56 by sde-smed          #+#    #+#              #
#    Updated: 2022/11/30 12:51:17 by sde-smed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
LIB		=	-L ./libft -lft -L ./printf -lprintf -L ./get_next_line -lgnl -L ./minilibx -lmlx -framework OpenGL -framework AppKit
SRCS	= 	main.c\
			utils.c\
			check.c
			
LIBFT	= libft/
GNL	= get_next_line/
PRINTF	= printf/


OBJS = $(SRCS:.c=.o)

CC			=	cc

FLAG = -Wall -Wextra -Werror

RM		= rm -rf

$(OBJ): $(SRC)
	@gcc $(FALGS) -c $(SRC)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(GNL)
	@make -C $(PRINTF)
	@gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	
	
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