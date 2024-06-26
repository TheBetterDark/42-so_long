# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/05/17 21:32:48 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = ./includes
LIBS = ./libs

LIBFT = $(LIBS)/libft
MLX = $(LIBS)/minilibx-linux

CC = cc
CFLAGS = -Wall -Werror -Wextra 
LINKFLAGS = -L$(LIBFT) -L$(MLX) -lmlx -lXext -lX11 -lm
DEBUGFLAGS = -g3

SRC_DIR = ./src
OBJ_DIR =./build
LOG_DIR = ./logs

OUTPUT_LEAKS = $(LOG_DIR)/valgrind.log

# DO NOT SUBMIT WITH THIS: DOUBLE CHECK IF WE CAN USE THIS
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUG) -I$(INCLUDES) -I$(LIBFT) -I$(MLX) -c $< -o $@

${NAME}: libft mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKFLAGS) -o $(NAME)

libft:
	@make -C $(LIBFT)

mlx:
	@make -C $(MLX)

clean:
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)

fclean:
	@make clean -C $(MLX)
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)

leaks: all
	@rm -f $(OUTPUT_LEAKS)
	@mkdir -p $(LOG_DIR)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat $(LOG_DIR)/valgrind.log

.PHONY: all clean fclean re libft mlx leaks test