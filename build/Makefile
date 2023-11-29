# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/29 13:25:02 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[38;5;196;1m
ORANGE = \033[38;5;208;1m
YELLOW = \033[38;5;226;1m
GREEN = \033[38;5;082;1m
BLUE = \033[38;5;027;1m
INDIGO = \033[38;5;093;1m
VIOLET = \033[38;5;163;1m
WHITE = \033[38;5;231;1m
END = \033[0m



NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP
RM = rm -rf

LIBFT = 		../library/libft/build/libft.a
PRINTF = 		../library/printf/build/printf.a

SRCS = 	main.c print.c free.c parse.c

OBJ_DIR = ../object
OBJS = $(addprefix ../object/, $(SRCS:.c=.o))
DEPS = $(addprefix ../object/, $(SRCS:.c=.d))

all: $(LIBFT) $(PRINTF) $(NAME)

.SILENT:

../object/%.o: ../source/%.c 
	mkdir -p $(dir $@)
	printf "$(ORANGE).$(END)";
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CC_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)
	printf "\r$(GREEN)🚀 ./$(NAME)      created                    \n$(END)"

$(LIBFT):
	printf "$(ORANGE)🔁 ./$(NAME)    compiling$(END)"
	make bonus -sC ../library/libft/build

$(PRINTF):
	printf "$(ORANGE).$(END)";
	make  -sC ../library/printf/build

clean:
	$(RM) $(OBJ_DIR)
	make clean -sC ../library/libft/build
	make clean -sC ../library/printf/build
	printf "$(RED)💥 object files\tremoved\n$(END)"

fclean: clean
	make fclean -sC ../library/libft/build
	make fclean -sC ../library/printf/build
	$(RM) $(NAME)
	printf "$(RED)💥 ./$(NAME) \tremoved\n$(END)"

re: _reprint fclean all

_reprint:
	printf "$(ORANGE)🚧 ./$(NAME)\trebuild\n$(END)"

nothing:
	printf "$(WHITE)💩 made $(RED)n$(ORANGE)o$(YELLOW)t$(GREEN)h$(BLUE)i$(INDIGO)n$(VIOLET)g\n$(END)"

-include $(DEPS)

.PHONY: all clean fclean re _Yreprint nothing