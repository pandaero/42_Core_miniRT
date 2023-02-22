# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:36:19 by pandalaf          #+#    #+#              #
#    Updated: 2023/02/22 19:00:58 by pbiederm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME	:= minirt

# Compiler options
CC		:= cc
CFLAGS	:= #-Wall -Werror -Wextra
COPT	:= #-g -fsanitize=address

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

#Paste below to makefile for tests

help:
	@echo "for series of cylinder tests enter: 'make a'"
	@echo "for series of cylinder sphere tests enter: 'make b'"
	@echo "for series of cylinder sphere tests with logs enter: 'make c'"
	@echo "for cylinder and sphere tests with logs enter: 'make d'"
	@echo "for plane cylinder calibration tests enter: 'make e'"

e:
	@echo "plane on zero"
	@./minirt test/calibration/test_input_one_7_plane_zero.rt > zero_plane.log
	@echo "plane on zero cylinder on zero, base"
	@./minirt test/calibration/test_input_one_8_cylinder_aligned_with_plane.rt > plane_cy.log
	@echo "plane on zero, cylinder on zero, top cap"
	@./minirt test/calibration/test_input_one_9_cylinder_reversed.rt > pl_cy_rev.log
	@echo "plane on zero, cylinder on zero, base cap, view from inside the cylinder"
	@./minirt test/calibration/test_input_one_10_inside_in_viev_rev_y.rt > pl_cy_inside_base.log
	@echo "plane on zero, cylinder on zero, top cap, view from inside the cylinder"
	@./minirt test/calibration/test_input_one_11_inside_viev_towards_top.rt > pl_cy_inside_top.log
	
d:
	@echo "cylinder of radius 35"
	@./minirt test/calibration/test_input_one_1_cylinder_center_radius_35.rt > cyl_sp_1.log
	@echo "sphere of radius 35"
	@./minirt test/calibration/test_input_one_2_sphere_center_radius_35.rt > cy_sp_2.log

c:
	@echo "cylinder of radius 35"
	@./minirt test/calibration/test_input_one_1_cylinder_center_radius_35.rt > cyl_sp_1.log
	@echo "sphere of radius 35"
	@./minirt test/calibration/test_input_one_2_sphere_center_radius_35.rt > cy_sp_2.log
	@echo "both sphere and cylinder in the same spot, same colour"
	@./minirt test/calibration/test_input_one_3_cylinder_sphere_center_radius_35.rt > cy_sp_3.log
	@echo "sphere and cylinder in the same spot, sphere is double the cylinder radius"
	@./minirt test/calibration/test_input_one_4_cylinder_35_sphere_70.rt > cy_sp_4.log
	@echo "sphere and cylinder in the same spot, sphere is double the cylinder radius, colour different"
	@./minirt test/calibration/test_input_one_5_cylinder_35_sphere_70_colour_diff.rt > cy_sp_5.log
	@echo "sphere and cylinder in the same spot, sphere is double the cylinder radius, colour different"
	@./minirt test/calibration/test_input_one_6_cylinder_dir_along_y_35_sphere_70_colour_diff.rt > cy_sp_5.log

b:
	@echo "cylinder of radius 35"
	@./minirt test/calibration/test_input_one_1_cylinder_center_radius_35.rt
	@echo "sphere of radius 35"
	@./minirt test/calibration/test_input_one_2_sphere_center_radius_35.rt
	@echo "both sphere and cylinder in the same spot, same colour"
	@./minirt test/calibration/test_input_one_3_cylinder_sphere_center_radius_35.rt
	@echo "sphere and cylinder in the same spot, sphere is double the cylinder radius"
	@./minirt test/calibration/test_input_one_4_cylinder_35_sphere_70.rt
	@echo "sphere and cylinder in the same spot, sphere is double the cylinder radius, colour different"
	@./minirt test/calibration/test_input_one_5_cylinder_35_sphere_70_colour_diff.rt
	@echo "sphere and cylinder in the same spot, sphere is double the cylinder radius, cylinder along y colour different"
	@./minirt test/calibration/test_input_one_6_cylinder_dir_along_y_35_sphere_70_colour_diff.rt

a:
	@echo "cylinder not seen" 
	@./minirt test/cylinder/test_input_one_cylinder_1_not_seen.rt 
	@echo "cylinder seen from outside"
	@./minirt test/cylinder/test_input_one_cylinder_2_seen.rt
	@echo "cylinder seen from point to the right"
	@./minirt test/cylinder/test_input_one_cylinder_3_seen_from_right.rt
	@echo "cylinder seen from point to the left"
	@./minirt test/cylinder/test_input_one_cylinder_4_seen_from_left.rt
	@echo "cylinder seen from inside negative direction"
	@./minirt test/cylinder/test_input_one_cylinder_5_inside_negative_dir.rt
	@echo "cylinder seen from inside positive direction"
	@./minirt test/cylinder/test_input_one_cylinder_6_inside_positive_dir.rt
	@echo "cylinder seen from the other side"
	@./minirt test/cylinder/test_input_one_cylinder_7_outside_seen.rt
	@echo "cylinder not seen from the other side"
	@./minirt test/cylinder/test_input_one_cylinder_8_outside_not_seen.rt
	@echo "cylinder seen from a point to the right, positve y coordinate in point"
	@./minirt test/cylinder/test_input_one_cylinder_9_seen_from_right.rt
	@echo "cylinder seen from a point to the left, negative y coordinate in point"
	@./minirt test/cylinder/test_input_one_cylinder_10_seen_from_left.rt
	@echo "cylinder seen from above"
	@./minirt test/cylinder/test_input_one_cylinder_11_seen_from_up.rt

# Make sure these aren't treated as files
.PHONY: all directory clean fclean re
