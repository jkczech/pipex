# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2023/12/14 15:52:38 by jkoupy           ###   ########.fr        #
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
BROWN = \033[38;5;137;1m
END = \033[0m

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror #-MD -MP
RM = rm -rf

LIBFT = 	../library/libft/build/libft.a

SRCS = 	      main.c free.c parse.c child.c error.c pipex.c
BSRCS = bonus_main.c free.c parse.c child.c error.c pipex.c
OBJ_DIR = ../object
OBJS =  $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BOBJS = $(addprefix $(OBJ_DIR)/, $(BSRCS:.c=.o))
#DEPS = $(addprefix ../object/, $(SRCS:.c=.d))

all: $(LIBFT) $(NAME)

../object/%.o: ../source/%.c 
	@mkdir -p $(dir $@)
	@printf "$(ORANGE).$(END)";
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(LIBFT) $(OBJS) 
	@$(CC) $(OBJS) $(CC_FLAGS) $(LIBFT) -o $(NAME)
	@printf "\r$(GREEN)🚀 ./$(NAME)      created (mandatory)        \n$(END)"

bonus: $(LIBFT) $(BOBJS)
	@if [ -e $(OBJ_DIR)/main.o ]; then \
		rm $(OBJ_DIR)/main.o; \
	fi
	@$(CC) $(BOBJS) $(CC_FLAGS) $(LIBFT) -o $(NAME)
	@printf "\r$(GREEN)🚀 ./$(NAME)      created (bonus)            \n$(END)"

$(LIBFT):
	@printf "$(ORANGE)🔁 ./$(NAME)    compiling$(END)"
	@make bonus -sC ../library/libft/build

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -sC ../library/libft/build
	@printf "$(RED)💥 object files\tremoved\n$(END)"

fclean: clean
	@make fclean -sC ../library/libft/build
	@$(RM) $(NAME)
	@printf "$(RED)💥 ./$(NAME) \tremoved\n$(END)"

#clean files other than 'Makefile' or 'pipex'
cleanf:
	@printf "$(RED)💥 test files \tremoved\n$(END)"
	@find . -type f ! -name 'Makefile' ! -name 'pipex' -delete

re: _rebuild fclean all

_rebuild:
	@printf "$(ORANGE)🚧 ./$(NAME)\trebuild\n$(END)"

nothing:
	@printf "💩$(BROWN) made $(RED)n$(ORANGE)o$(YELLOW)t$(GREEN)h$(BLUE)i$(INDIGO)n$(VIOLET)g\n$(END)"

#-include $(DEPS)

.PHONY: all clean fclean cleanf re _rebuild nothing