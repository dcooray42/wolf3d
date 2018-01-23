# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcooray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 13:57:31 by dcooray           #+#    #+#              #
#    Updated: 2017/05/17 09:28:55 by dcooray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs/

SRC_PRINTF_PATH = ./srcs_printf/

OBJ_PATH = ./objs/

SRC_NAME = ft_memset.c \
	 	ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_atoif.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isxdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_itoa_base_usigned.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putwchar.c \
		ft_putwstr.c \
		ft_wstrlen.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strdeljoin.c \
		get_next_line.c

SRC_PRINTF_NAME = ft_printf.c \
			ft_printf_bis.c \
			ft_printf_flag.c \
			ft_printf_champ.c \
			ft_printf_specifier.c \
			ft_printf_arg_mod.c \
			ft_printf_arg_mod_bis.c \
			ft_printf_arg_s.c \
			ft_printf_arg_s_print.c \
			ft_printf_arg_ls_print.c \
			ft_printf_arg_p.c \
			ft_printf_arg_p_print.c \
			ft_printf_arg_di.c \
			ft_printf_arg_di_pos_zero_print.c \
			ft_printf_arg_di_pos_zero_print_bis.c \
			ft_printf_arg_di_neg_print.c \
			ft_printf_arg_ld.c \
			ft_printf_arg_ld_print.c \
			ft_printf_arg_o.c \
			ft_printf_arg_o_print.c \
			ft_printf_arg_lo.c \
			ft_printf_arg_lo_print.c \
			ft_printf_arg_u.c \
			ft_printf_arg_u_print.c \
			ft_printf_arg_lu.c \
			ft_printf_arg_lu_print.c \
			ft_printf_arg_x.c \
			ft_printf_arg_x_print.c \
			ft_printf_arg_lx.c \
			ft_printf_arg_lx_print.c \
			ft_printf_arg_c.c \
			ft_printf_arg_c_print.c \
			ft_printf_reset.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PRINTF_NAME = $(SRC_PRINTF_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME) \
				$(SRC_PRINTF_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME) $(OBJ_PRINTF_NAME))

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<
$(OBJ_PATH)%.o: $(SRC_PRINTF_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
