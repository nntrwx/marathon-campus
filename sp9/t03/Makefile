NAME = minilibmx.a
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRCS = $(SRC_DIR)/mx_atoi.c $(SRC_DIR)/mx_isdigit.c $(SRC_DIR)/mx_isspace.c \
       $(SRC_DIR)/mx_printchar.c $(SRC_DIR)/mx_printint.c $(SRC_DIR)/mx_printstr.c \
       $(SRC_DIR)/mx_strcpy.c $(SRC_DIR)/mx_strcmp.c $(SRC_DIR)/mx_strlen.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
AR = ar rcs

all: $(NAME)

MINILIBMX: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

uninstall: clean
	rm -f $(NAME)

reinstall: uninstall all
