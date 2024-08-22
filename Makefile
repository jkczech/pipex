# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2024/08/22 10:53:00 by jkoupy           ###   ########.fr        #
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
BNAME = pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = 	library/libft/build/libft.a
GETNEXTLINE = 	library/get_next_line/build/getnextline.a

MSRCS = main.c free.c parse.c child.c error.c pipex.c here_doc.c
BSRCS = main_bonus.c free.c parse.c child.c error.c pipex.c here_doc.c
OBJ_DIR = object/
MOBJS =  $(addprefix $(OBJ_DIR), $(MSRCS:.c=.o))
BOBJS = $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

all: $(LIBFT) $(GETNEXTLINE) $(NAME)

bonus: $(LIBFT) $(GETNEXTLINE) $(BNAME)

both: all bonus

object/%.o: source/%.c 
	@mkdir -p $(dir $@)
	@printf "$(ORANGE).$(END)";
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(LIBFT) $(MOBJS) 
	@$(CC) $(MOBJS) $(CC_FLAGS) $(LIBFT) $(GETNEXTLINE) -o $(NAME)
	@printf "\r$(GREEN)🚀 ./$(NAME)       created              \n$(END)"

$(BNAME): $(LIBFT) $(BOBJS)
	@$(CC) $(BOBJS) $(CC_FLAGS) $(LIBFT) $(GETNEXTLINE) -o $(BNAME)
	@printf "\r$(GREEN)🚀 ./$(BNAME) created                    \n$(END)"

$(LIBFT):
	@printf "$(ORANGE)🔁 ./$(NAME) \t compiling$(END)"
	@make bonus -sC library/libft/build

$(GETNEXTLINE):
	@printf "$(ORANGE).$(END)"
	@make -sC library/get_next_line/build

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -sC library/libft/build
	@make clean -sC library/get_next_line/build
	@printf "$(RED)💥 object files\t removed\n$(END)"

fclean: clean
	@make fclean -sC library/libft/build
	@make fclean -sC library/get_next_line/build
	@$(RM) $(NAME) $(BNAME)
	@printf "$(RED)💥 ./$(NAME) \t removed\n$(END)"

cleanf:
	@printf "$(RED)💥 test files \t removed\n$(END)"
	@find . -type f ! -name 'Makefile' ! -name $(NAME) ! -name $(BNAME) -delete

re: _rebuild fclean all

_rebuild:
	@printf "$(ORANGE)🚧 ./$(NAME)\t rebuild\n$(END)"

nothing:
	@printf "💩$(BROWN) made $(RED)n$(ORANGE)o$(YELLOW)t$(GREEN)h$(BLUE)i$(INDIGO)n$(VIOLET)g\n$(END)"

.PHONY: all bonus both clean fclean cleanf re _rebuild nothing