# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/21 13:59:49 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[31;1m
GREEN = \033[32;1m
ORANGE = \033[33;1m

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
	printf "$(ORANGE).$(END)";
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CC_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)
	printf "\r$(GREEN)✅ ./$(NAME) \tcreated                    \n$(END)"

$(LIBFT):
	printf "$(ORANGE)🔁 ./$(NAME)\tcompiling.$(END)"
	make bonus -sC ../library/libft/build

$(PRINTF):
	printf "$(ORANGE).$(END)";
	make  -sC ../library/printf/build

clean:
	$(RM) ../object
	make clean -sC ../library/libft/build
	make clean -sC ../library/printf/build
	printf "$(RED)💥 object files\tremoved\n$(END)"

fclean: clean
	make fclean -sC ../library/libft/build
	make fclean -sC ../library/printf/build
	$(RM) $(NAME)
	printf "$(RED)💥 ./$(NAME) \tremoved\n$(END)"

re: reprint fclean all
	
reprint:
	printf "$(ORANGE)🚧 ./$(NAME)\trebuild\n$(END)"

shit:
	printf "$(ORANGE)💩 made shit\n$(END)"

-include $(DEPS)

.PHONY: all clean fclean re