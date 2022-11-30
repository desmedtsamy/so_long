# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:24:14 by samy              #+#    #+#              #
#    Updated: 2022/11/30 13:43:14 by sde-smed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRCS = 	ft_printf.c\
		ft_printf_utils.c\
		ft_printf_utils_print.c
		
OBJS = $(SRCS:.c=.o)

CC			=	cc

FLAG = -Wall -Wextra -Werror

ARRCS		=	ar rcs

RM		= rm -rf

.c.o:	$(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)

	@echo "make printf"
	@$(ARRCS) $(NAME) $^
	
all: $(NAME)

clean:

	@echo "make clean printf"
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:			all clean fclean re
