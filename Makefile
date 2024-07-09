# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/07/08 16:53:24 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = ./includes
LIBS = ./libs

LIBFT = $(LIBS)/libft
MLX = $(LIBS)/minilibx-linux

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 #! Remember to remove -g3 flag

INCLUDEFLAGS = -I$(INCLUDES) -I$(MLX) -I$(LIBFT)/includes
LINKFLAGS = -lmlx -lXext -lX11 -lm -lft

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

SRC_DIR = ./src
BONUS_DIR = ./src_bonus
OBJ_DIR = ./bin
OBJ_BONUS_DIR = ./bin_bonus
LOG_DIR = ./logs

OUTPUT_LEAKS = $(LOG_DIR)/valgrind.log

SRCS = $(shell find $(SRC_DIR) -name '*.c')
SRCS_BONUS = $(shell find $(BONUS_DIR) -name '*.c')

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

all: $(NAME) $(OBJ_DIR)

$(OBJ_DIR):
	@echo "${YELLOW}Creating object directory $(OBJ_DIR)...${NC}"
	@mkdir -p $(OBJ_DIR)
	@echo "${GREEN}Object directory $(OBJ_DIR) created.${NC}"

$(OBJ_BONUS_DIR):
	@echo "${YELLOW}Creating object directory $(OBJ_BONUS_DIR)...${NC}"
	@mkdir -p $(OBJ_BONUS_DIR)
	@echo "${GREEN}Object directory $(OBJ_BONUS_DIR) created.${NC}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c $< -o $@

${NAME}: $(OBJS)
	@make -C $(MLX)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -L$(MLX) $(LINKFLAGS) -o $(NAME)
	@echo "${GREEN}$(NAME) created.${NC}"

bonus: $(OBJS_BONUS)
	@make -C $(MLX)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT) -L$(MLX) $(LINKFLAGS) -o $(NAME)
	@echo "${GREEN}$(NAME) bonus created.${NC}"

clean:
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LOG_DIR)

fclean:
	@make clean -C $(MLX)
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@rm -f $(NAME)
	@rm -rf $(LOG_DIR)
	@echo "${GREEN}$(NAME) cleaned.${NC}"

re: fclean all
	@echo "${GREEN}Target 're' completed.${NC}"

libs:
	@echo "${YELLOW}Updating submodules...${NC}"
	@git submodule update --init --recursive --remote
	@echo "${GREEN}Submodules updated.${NC}"

.PHONY: all clean fclean re bonus libs
