CC = clang
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
AR = ar rcs

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

NAME = libhcb_server.a

SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(BIN_DIR)/$(NAME)

# static library output
$(BIN_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(AR) $@ $^

# compile rule (mirrors folder structure)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
