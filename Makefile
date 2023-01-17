# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:36:19 by pandalaf          #+#    #+#              #
#    Updated: 2023/01/17 15:02:05 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME	:= minirt

# Compiler options
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= #-g -fsanitize=address

# Sources
SRC_ROOT	:= src/
SRC_DIRS	:= calculation/ elements/ error/ intersection/ memory/ object/ \
				program/
$(info $(SRC_DIRS))
SRCS		:= $(wildcard $(SRC_DIR)*.c)

# Objects to compile
OBJ_DIR	:= build/
OBJS	:= $(patsubst %.c, %.o, $(notdir $(SRCS)))
OBJS	:= $(addprefix $(OBJ_DIR), $(OBJS))

################################ DEPENDENCIES ##################################
# Libft
LIBFT		:= libft.a
LIBFT_DIR	:= libft/
LIBFT_FULL	:= $(addprefix $(LIBFT_DIR), $(LIBFT))

# MiniLibX, checks OS to choose which to make
ifeq ($(shell uname -s), Darwin)
MLX			:= libmlx.a
MLX_DIR		:= minilibx_opengl_20191021/
else
MLX			:= libmlx_Linux.a
MLX_DIR		:= minilibx-linux/
endif
MLX_FULL	:= $(addprefix $(MLX_DIR), $(MLX))

# Libraries, checks OS to choose which to include
ifeq ($(shell uname -s), Darwin)
LIBS	:= $(LIBFT_FULL) $(MLX_FULL)
else
LIBS	:= $(LIBFT_FULL) $(MLX_FULL) -lX11 -lXext -lm
endif

# Look for (.c) files in the following directory if not found elsewhere.
vpath %.c $(SRC_ROOT)

#################################### RULES #####################################
# Make desired target
all: directory $(NAME)

# Make required directory
directory: $(OBJ_DIR)

# Make the target executable
$(NAME): $(OBJS) $(MLX_FULL) $(LIBFT_FULL)
	$(CC) $(CFLAGS) $(COPT) $< $(filter-out $<, $^) -o $@ $(LIBS)

# Make the object files
$(addprefix $(OBJ_DIR), %.o): $(addprefix $(SRC_DIR), %.c) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@

# Make the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Make the libft archive
$(LIBFT_FULL): $(LIBFT_DIR)
	make -C $(LIBFT_DIR) all

# Make the minilibx archive
$(MLX_FULL): $(MLX_DIR)
	make -C $(MLX_DIR) all

# Clean intermediate files
clean:
	make -C $(LIBFT_DIR) clean
	mkdir -p copy
	mv $(MLX_FULL) copy
	make -C $(MLX_DIR) clean
	mv $(addprefix copy/, $(MLX)) $(MLX_FULL)
	rm -rf copy/
	rm -rf $(OBJ_DIR)

# Clean all non-source files
fclean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(MLX_FULL)
	rm -rf $(addprefix $(MLX_DIR), test)
	rm -f $(addprefix $(MLX_DIR), Makefile.gen)
	rm -f $(NAME)

# Clean everything and re-compile
re: fclean all

# Make sure these aren't treated as files
.PHONY: all directory clean fclean re
