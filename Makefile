# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smortier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 23:18:45 by smortier          #+#    #+#              #
#    Updated: 2018/01/24 23:27:26 by smortier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC_NAME	=	main.c \
				key_holder.c \
				init_drawing.c \
				ft_mandelbrot.c

OBJ_NAME	=	$(SRC:.c=.o)
SRC_PATH	=	./src
OBJ_PATH	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-I./includes

LDLIBS		=	-lft
LDFLAGS		=	-Llibft

FLAGS1 = -framework OpenGL -framework AppKit

MLX = minilibx

all: $(NAME)

$(NAME): $(OBJ) MLX
	@$(MAKE) -s -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(LDFLAGS) $(FLAGS1) $(LDLIBS) $(OBJ) -o $(NAME) -L./minilibx -lmlx -Lft_printf -lftprintf

MLX : $(MLX)
	@make -s -C $(MLX)/

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
