# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 11:34:29 by gifulvi           #+#    #+#              #
#    Updated: 2022/11/10 16:06:42 by gifulvi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO = philo

CFLAGS = -Wall -Wextra -Werror -pthread

PHILO_SRCS = philo_main.c checkers.c utils.c initializers.c printers.c operations.c \
ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putunsigned.c ft_itoa.c \
ft_putstr.c

OBJ = *.o

CC = gcc

HEADER = lib.h

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

all: $(PHILO)

$(PHILO):

	@echo "$(WHT)Compiling philo...$(EOC)"
	@$(CC) $(CFLAGS) -c $(PHILO_SRCS) -I$(HEADER)
	@$(CC) $(CFLAGS) -o $(PHILO) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj
	@echo "$(GREEN)philo build completed.$(EOC)"

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(PHILO)
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re
