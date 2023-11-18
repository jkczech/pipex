# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:10:19 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/17 19:04:14 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
LIBFT = ../../libft/build/libft.a
SRCS = ft_is.c ft_print_flag.c ft_printf.c ft_putnbr_base.c ft_putptr.c

OBJS = $(addprefix ../object/, $(SRCS:.c=.o))
DEPS = $(addprefix ../object/, $(SRCS:.c=.d))

.SILENT:

all:	$(LIBFT) $(NAME)

../object/%.o: ../source/%.c 
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	printf "\033[32m.\033[0m"
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -sC ../../libft/build

clean:
	$(RM) ../object
	make clean -sC ../../libft/build

fclean: clean
	$(RM) $(NAME)
	make -s fclean -C ../../libft/build

re: fclean all

.PHONY: all clean fclean re
