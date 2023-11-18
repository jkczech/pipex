# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/18 15:22:35 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[31m
GREEN = \033[32m

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP
RM = rm -rf

LIBFT = 		../library/libft/build/libft.a
PRINTF = 		../library/printf/build/printf.a

SRCS = 	main.c

OBJ_DIR = object
OBJS = $(addprefix ../object/, $(SRCS:.c=.o))
DEPS = $(addprefix ../object/, $(SRCS:.c=.d))

all: $(LIBFT) $(PRINTF) $(NAME)

.SILENT:

../object/%.o: ../source/%.c 
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CC_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)
	printf "\r$(GREEN)✅ $(NAME) created         \n$(END)"

$(LIBFT):
	printf "\r$(GREEN)$(NAME) compiling.$(END)"
	make bonus -sC ../library/libft/build

$(PRINTF):
	printf "$(GREEN).$(END)"
	make  -sC ../library/printf/build

clean:
	$(RM) ../object
	make clean -sC ../library/libft/build
	make clean -sC ../library/printf/build
	printf "$(RED)🗑️  object files removed\n$(END)"

fclean: clean
	make fclean -sC ../library/libft/build
	make fclean -sC ../library/printf/build
	$(RM) $(NAME)
	printf "$(RED)🗑️  $(NAME) removed\n$(END)"

re: fclean all

valgrind: all
	valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no ./$(NAME) $(ARG)

funcheck: all
	funcheck ./$(NAME) $(ARG)

funchecka: all
	funcheck -a ./$(NAME) $(ARG)

-include $(DEPS)

.PHONY: all clean fclean re valgrind funcheck funchecka