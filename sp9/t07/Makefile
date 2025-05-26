CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

NAME = calc

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INCLUDES = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

uninstall: clean
	rm -f $(NAME)

reinstall: uninstall all
