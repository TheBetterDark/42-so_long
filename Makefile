# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/05/24 23:11:10 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = ./includes
LIBS = ./libs

LIBFT = $(LIBS)/libft
MLX = $(LIBS)/minilibx-linux

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 #! Remember to remove -g3 flag

INCLUDEFLAGS = -I$(INCLUDES) -I$(LIBFT) -I$(MLX)
LINKFLAGS = -lmlx -lXext -lX11 -lm -lft #! Verify this

SRC_DIR = ./src
OBJ_DIR = ./bin
LOG_DIR = ./logs

OUTPUT_LEAKS = $(LOG_DIR)/valgrind.log

#! DO NOT SUBMIT WITH THIS:
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utils/events.c $(SRC_DIR)/utils/color.c \
# $(SRC_DIR)/utils/image.c $(SRC_DIR)/utils/render.c $(SRC_DIR)/utils/texture.c \
# $(SRC_DIR)/utils/window.c

# OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/utils/events.o $(OBJ_DIR)/utils/color.o \
# $(OBJ_DIR)/utils/image.o $(OBJ_DIR)/utils/render.o $(OBJ_DIR)/utils/texture.o \
# $(OBJ_DIR)/utils/window.o

all: $(NAME) $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c $< -o $@

${NAME}: $(OBJS)
	@make -C $(MLX)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -L$(MLX) $(LINKFLAGS) -o $(NAME)

clean:
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LOG_DIR)

fclean:
	@make clean -C $(MLX)
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -rf $(LOG_DIR)

re: fclean all

libs:
	@git submodule update --init --recursive --remote

test: all
	./$(NAME)

leaks: all
	@rm -f $(OUTPUT_LEAKS)
	@mkdir -p $(LOG_DIR)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat $(LOG_DIR)/valgrind.log

.PHONY: all clean fclean re libs leaks test