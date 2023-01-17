# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:36:19 by pandalaf          #+#    #+#              #
#    Updated: 2023/01/18 00:13:14 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME	:= minirt

# Compiler options
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= -g -fsanitize=address

# Sources
SRC_ROOT	:= src/
SRC_SUBDIRS	:= calculation/ elements/ error/ intersection/ memory/ object/ \
				program/
SRC_DIR		:= $(addprefix $(SRC_ROOT), $(SRC_SUBDIRS))
SRCS		:= $(foreach subdir, $(SRC_DIR), $(wildcard $(subdir)*.c)) \
				$(addprefix $(SRC_ROOT), main.c)

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
MLX			:= libmlx.a
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
$(word 1, $(OBJS)): $(word 1, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 2, $(OBJS)): $(word 2, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 3, $(OBJS)): $(word 3, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 4, $(OBJS)): $(word 4, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 5, $(OBJS)): $(word 5, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 6, $(OBJS)): $(word 6, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 7, $(OBJS)): $(word 7, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 8, $(OBJS)): $(word 8, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 9, $(OBJS)): $(word 9, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 10, $(OBJS)): $(word 10, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 11, $(OBJS)): $(word 11, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 12, $(OBJS)): $(word 12, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 13, $(OBJS)): $(word 13, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 14, $(OBJS)): $(word 14, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 15, $(OBJS)): $(word 15, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 16, $(OBJS)): $(word 16, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 17, $(OBJS)): $(word 17, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 18, $(OBJS)): $(word 18, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 19, $(OBJS)): $(word 19, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 20, $(OBJS)): $(word 20, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 21, $(OBJS)): $(word 21, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 22, $(OBJS)): $(word 22, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 23, $(OBJS)): $(word 23, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 24, $(OBJS)): $(word 24, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 25, $(OBJS)): $(word 25, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 26, $(OBJS)): $(word 26, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 27, $(OBJS)): $(word 27, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 28, $(OBJS)): $(word 28, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 29, $(OBJS)): $(word 29, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 30, $(OBJS)): $(word 30, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 31, $(OBJS)): $(word 31, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 32, $(OBJS)): $(word 32, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@
$(word 33, $(OBJS)): $(word 33, $(SRCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@

# Make the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Make the libft archive
$(LIBFT_FULL): | $(LIBFT_DIR)
	make -C $(LIBFT_DIR) all

# Make the minilibx archive
$(MLX_FULL): | $(MLX_DIR)
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
	rm -f $(addprefix $(MLX_DIR), libmlx_Linux.a)
	rm -f $(addprefix $(MLX_DIR), Makefile.gen)
	rm -f $(NAME)

# Clean everything and re-compile
re: fclean all

# Make sure these aren't treated as files
.PHONY: all directory clean fclean re
