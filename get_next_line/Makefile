# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:43:52 by sde-smed          #+#    #+#              #
#    Updated: 2022/11/30 13:42:36 by sde-smed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libgnl.a

SRC = 	get_next_line_bonus.c\
		get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)

CC			=	cc

FLAG = -Wall -Wextra -Werror

ARRCS		=	ar rcs

RM		= rm -rf

.c.o:	$(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "make get_next_line"
	@$(ARRCS) $(NAME) $^
	
bonus: $(OBJ_BONUS) 
	$(ARRCS) $(NAME) $^
	
all: $(NAME)

clean:

	@echo "make clean get_next_line"
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:			all clean fclean re bonus