# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:36:19 by pandalaf          #+#    #+#              #
#    Updated: 2023/01/31 17:23:36 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME	:= minirt

# Compiler options
CC		:= cc
CFLAGS	:= 
COPT	:= -g #-fsanitize=address

# Sources
SRC_ROOT	:= src/
SRC_SUBDIRS	:= calculation/ elements/ error/ intersection/ memory/ object/ \
				program/ input/
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

# Frameworks, for Mac compilation.
ifeq ($(shell uname -s), Darwin)
FWK	:= -framework OpenGL -framework AppKit
else
FWK :=
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
	$(CC) $(CFLAGS) $(COPT) $(FWK) $< $(filter-out $<, $^) $(LIBS) -o $@ 

# Make the object file rule definition
define recursive_def
$(firstword $(1)): $(firstword $(2))
	$(CC) $(CFLAGS) $(COPT) -c $(firstword $(2)) -o $(firstword $(1))

$(if $(wordlist 2, 3, $1), $(call recursive_def, \
		$(wordlist 2, $(words $(1)), $1), $(wordlist 2, $(words $(2)), $(2))))
endef

# Make the object file rules
$(eval $(call recursive_def, $(OBJS), $(SRCS)))

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
