# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 10:39:51 by pandalaf          #+#    #+#              #
#    Updated: 2022/06/03 11:13:49 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := libft.a
# Compiler options
CC := cc
CFLAGS := -Wall -Wextra -Werror
# Source files to include
SRCS :=	ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c \
		ft_print_str.c ft_print_unsigned.c ft_print_ptr.c type_reader.c \
		get_next_line.c get_next_line_utils.c
# Source files to include in the bonus
BSRCS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c 
# Object files to create (in directory)
OBJ_DIR := obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BOBJS = $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

# Make desired targets
all: directories $(NAME)

# Make required directories
directories: $(OBJ_DIR)

# Make standard libft archive
$(NAME): $(OBJS)
	ar -rcs $@ $^

# Make the object files
$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

# Make the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Make bonus libft archive
bonus: $(OBJS) $(BOBJS)
	ar -rcs $(NAME) $^	

# Clean intermediary files
clean:
	rm -fr $(OBJ_DIR)

# Clean all non-source files
fclean: clean
	rm -f $(NAME)

# Wipe all and make again
re: fclean all

# Make sure these aren't treated as files
.PHONY: all clean fclean re bonus directories
