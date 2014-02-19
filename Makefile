# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/10 13:43:05 by mmartin           #+#    #+#              #
#    Updated: 2014/02/16 10:00:53 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.source

export	CC		=	gcc

export	CFLAGS	=	-Wall -Werror -Wextra -g

export	INC		=	-I $(PWD)/libft/includes

NAME		=	rt_v1

INC			+=	-I includes

SRC			=	main.c				\
				ft_obj.c			\
				ft_struct.c			\
				ft_camera.c			\
				ft_parsing.c		\
				ft_vec_ope.c		\
				ft_vec_tools.c		\
				ft_get_light.c		\
				ft_raytracing.c		\
				ft_find_inter.c		\
				ft_find_color.c		\
				ft_vec_rotation.c	\

OBJ			=	$(SRC:.c=.o)

HEAD		=	includes/ft_rtv1.h

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
