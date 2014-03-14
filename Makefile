# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/10 13:43:05 by mmartin           #+#    #+#              #
#    Updated: 2014/03/14 19:35:18 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.source

export	CC		=	gcc

export	CFLAGS	=	-Wall -Werror -Wextra -g

export	INC		=	-I $(PWD)/libft/includes

NAME		=	rt

INC			+=	-I includes

SRC			=	main.c					\
				ft_raytracing.c			\
				ft_find_inter.c			\
				ft_find_color.c			\
				vector/ft_vec_ope.c		\
				vector/ft_vec_tools.c	\
				vector/ft_vec_rotation.c\
				parsing/ft_struct.c		\
				parsing/ft_camera.c		\
				parsing/ft_parsing.c	\
				parsing/ft_get_light.c	\
				objects/ft_cone.c		\
				objects/ft_plane.c		\
				objects/ft_sphere.c		\
				objects/ft_cylinder.c	\

OBJ			=	$(SRC:.c=.o)

HEAD		=	includes/ft_rt.h

LIB			=	-L ./ -lft -L /usr/X11/lib -lmlx -lXext -lX11

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/includes/libft.h libft/includes/get_next_line.h

all:		$(NAME)

libft.a:	libft/$(OBJ_LIB) $(HEAD_LIB)
	@Make -C libft

$(NAME):	$(OBJ)
	@echo ""
	@echo "\033[33m"Compilation of rt : "\033[32m"Success"\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(OBJ):		$(HEAD) libft.a

%.o:		%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of rt : deleted"\033[0m"

fclean:		clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"rt : delete"\033[0m"
	@Make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
