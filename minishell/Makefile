.PHONY: all clean fclean re norme

##CC = clang-9
CC = clang -g ## clang-9 doesn't work ion my ubuntu

FLAGS = -Wall -Wextra -Werror

NAME = minishell

SRC_PATH = ./srcs
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

INC_NAME = minishell.h
SRC_NAME = clean.c error.c main.c minishell.c quit.c signal.c
LIB_NAME = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	${CC} -Wall -Wextra -Werror -I ${INC_PATH} -o ${NAME} ${OBJLIB} ${OBJ}

valgrind: $(OBJ) $(OBJLIB)
	${CC} -Wall -Wextra -Werror -g -o ${NAME} ${OBJLIB} ${OBJ} 
	valgrind --leak-check=full --show-leak-kinds=all ./minishell
	#valgrind --leak-check=full ./minishell

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	${CC} -I ${INC_PATH} -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	rm -rf ./obj $(NAME)

re: fclean all