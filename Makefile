# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:38:54 by fabou-za          #+#    #+#              #
#    Updated: 2022/06/17 18:23:43 by fabou-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME1 = fractol_bonus
FLAGS = -Wall -Wextra -Werror
INC= fractol.h
INC1= fractol_bonus.h
OBJ = fill_pixel.o \
	  fractol_utils.o \
	  fractals.o \
	  init_funcs.o \
	  fractol.o \
	  mapping_funcs.o \
	  key_handler.o \
	  zoom.o
OBJ_BONUS = fill_pixel_bonus.o \
			fractol_utils_bonus.o \
			fractals_bonus.o \
			mapping_funcs_bonus.o \
			init_funcs_bonus.o \
			fractol_bonus.o \
			key_handler_bonus.o \
			zoom_bonus.o

all : $(NAME)

%.o : %.c $(INC)
	gcc $(FLAGS) -c -o $@ $< -I $(INC)

$(NAME) : $(OBJ)
	gcc -o $@ $^ -lmlx -framework OpenGL -framework AppKit\
        -I $(INC)

bonus : $(NAME1)

%.o : %.c $(INC1)
	gcc $(FLAGS) -c -o $@ $< -I $(INC1)

$(NAME1) : $(OBJ_BONUS)
	gcc -o $@ $^ -lmlx -framework OpenGL -framework AppKit\
		-I $(INC1)
clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME1)
	
re : fclean all
