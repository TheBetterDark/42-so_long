# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/05/24 23:45:08 by muabdi           ###   ########.fr        #
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
LINKFLAGS = -lmlx -lXext -lX11 -lm -lft #! Verify this

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

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
	@echo "${YELLOW}Creating object directory $(OBJ_DIR)...${NC}"
	@mkdir -p $(OBJ_DIR)
	@echo "${GREEN}Object directory $(OBJ_DIR) created.${NC}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c $< -o $@

${NAME}: $(OBJS)
	@make -C $(MLX)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -L$(MLX) $(LINKFLAGS) -o $(NAME)
	@echo "${GREEN}$(NAME) created.${NC}"

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
	@echo "${GREEN}$(NAME) cleaned.${NC}"

re: fclean all
	@echo "${GREEN}Target 're' completed.${NC}"

libs:
	@echo "${YELLOW}Updating submodules...${NC}"
	@git submodule update --init --recursive --remote
	@echo "${GREEN}Submodules updated.${NC}"


leaks: all
	@rm -f $(OUTPUT_LEAKS)
	@mkdir -p $(LOG_DIR)
	@valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat $(OUTPUT_LEAKS) | grep -E "HEAP SUMMARY:|LEAK SUMMARY:|in use as exit:|total heap usage:|definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:"
	@if [ $$? -eq 0 ]; then echo "${GREEN}No memory leaks detected.\n$(NAME) ran successfully.${NC}"; else echo "${RED}Memory leaks detected.\n${YELLOW}Check $(OUTPUT_LEAKS) for more information.${NC}"; fi
		
.PHONY: all clean fclean re libs leaks test