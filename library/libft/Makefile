END = \033[0m
RED = \033[31;1m
GREEN = \033[32;1m
ORANGE = \033[38;5;208;1m

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c \
       ft_dtoa.c ft_strjoin3.c ft_strlwr.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
        ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
        ft_lstmap.c

OBJ_DIR = object
OBJS = $(addprefix object/, $(SRCS:.c=.o))
BOBJS = $(addprefix object/, $(SRCS:.c=.o))

#.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	printf "$(ORANGE).$(END)";
	$(AR) $@ $?

bonus: $(OBJS) $(BOBJS)
	$(AR) $(NAME) $(OBJS) $(BOBJS)

object/%.o: source/%.c 
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
