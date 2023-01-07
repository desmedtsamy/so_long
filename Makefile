# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samy <samy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:51:56 by sde-smed          #+#    #+#              #
#    Updated: 2023/01/07 01:21:02 by samy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
LIB		=	-L ./libft -lft -L /usr/local/include -lmlx -framework OpenGL -framework AppKit
SRCS	= 	src/mandatory/main.c\
			src/mandatory/utils.c\
			src/mandatory/check.c\
			src/mandatory/render.c\
			src/mandatory/check_access.c
			
BONUS_SRCS	= 	src/bonus/main_bonus.c\
			src/bonus/utils_bonus.c\
			src/bonus/check_bonus.c\
			src/bonus/render_bonus.c\
			src/bonus/init_game_bonus.c\
			src/bonus/check_access_bonus.c\
			src/bonus/move_bonus.c\
			src/bonus/sprites_bonus.c
			
LIBFT	= libft/

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
RM		= rm -rf

$(OBJ): $(SRC)
	@gcc $(FALGS) -c $(SRC)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	cc $(FLAGS) -g $(OBJS) $(LIB) -o $(NAME) -I $(LIBFT)
	
	
all: $(NAME)

bonus : $(OBJS_BONUS)
	@make -C $(LIBFT)
	cc $(FLAGS) -g $(OBJS_BONUS) $(LIB) -o $(NAME) -I $(LIBFT)
clean:
	@make -C $(LIBFT) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	@make -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY:			all clean fclean re