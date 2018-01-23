# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcooray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 09:28:36 by dcooray           #+#    #+#              #
#    Updated: 2017/07/19 18:22:02 by dcooray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

SRC_NAME = main.c\
		read.c\
		error.c\
		delete.c\
		mlx.c\
		mlx_bis.c\
		mlx_ter.c\
		calculus.c\
		render.c\
		render_bis.c\
		render_h.c\
		render_v.c\
		music.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

PATHFT = ./libft

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I ./includes

MACOSVERS := $(shell (sw_vers -productVersion | cut -b 1-5))

SIERRA = ./mlx/sierra

ELCAPITAN = ./mlx/el_capitan

LIBFT = -L$(PATHFT) -lft

OPENCL = -framework OpenCL

ifeq ($(MACOSVERS),10.11)
	MLXPATH = -L$(ELCAPITAN)
else ifeq ($(MACOSVERS),10.12)
	MLXPATH = -L$(SIERRA)
endif

MLX = $(MLXPATH) -lmlx -framework OpenGL -framework Appkit

FMOD = -Lfmod -lfmod

all: libft.a mlx.a $(NAME)

libft.a:
	make -C $(PATHFT)

mlx.a:
ifeq ($(MACOSVERS),10.11)
	make -C $(ELCAPITAN)
else ifeq ($(MACOSVERS),10.12)
	make -C $(SIERRA)
endif

$(NAME): $(OBJ)
	gcc $(FLAGS) $(INCLUDE) $(LIBFT) $(MLX) $(OPENCL) $(FMOD) -o $(NAME) $(OBJ)
	@install_name_tool -change @rpath/libfmod.dylib ./fmod/libfmod.dylib wolf3d

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	make -C $(ELCAPITAN) clean
	make -C $(SIERRA) clean
	make -C $(PATHFT) clean
	/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make -C $(PATHFT) fclean
	/bin/rm -f $(NAME)

re: fclean all

norminette:
	norminette ./libft/**/*[ch]
	norminette ./includes/wolf3d.h
	norminette ./srcs
