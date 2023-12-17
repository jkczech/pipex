# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 14:15:09 by jkoupy            #+#    #+#              #
#    Updated: 2023/12/17 02:04:38 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE = \033[38;5;208;1m
END = \033[0m

NAME = getnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(addprefix ../object/, $(SRCS:.c=.o))

.SILENCE:

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $?

../object/%.o: ../source/%.c
	@mkdir -p $(dir $@)
	@printf "$(ORANGE).$(END)";
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf ../object/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
