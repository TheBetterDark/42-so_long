# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/05/22 21:47:16 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = ./includes
LIBS = ./libs

LIBFT = $(LIBS)/libft
MLX = $(LIBS)/minilibx-linux

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LINKFLAGS = -L$(LIBFT) -L$(MLX) -lmlx -lXext -lX11 -lm -lft

SRC_DIR = ./src
UTILS_DIR = ./utils
OBJ_DIR =./bin
LOG_DIR = ./logs

OUTPUT_LEAKS = $(LOG_DIR)/valgrind.log

#! DO NOT SUBMIT WITH THIS:
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c)) \
       $(patsubst $(UTILS_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(UTILS_DIR)/*.c))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT) -I$(MLX) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT) -I$(MLX) -c $< -o $@

${NAME}: $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LINKFLAGS) -o $(NAME)

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

test: all
	./$(NAME)

leaks: all
	@rm -f $(OUTPUT_LEAKS)
	@mkdir -p $(LOG_DIR)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat $(LOG_DIR)/valgrind.log

.PHONY: all clean fclean re libft mlx leaks test