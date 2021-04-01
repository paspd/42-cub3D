# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2021/02/08 12:36:34 by leodauga          #+#    #+#              #
# #    Updated: 2021/02/19 09:50:30 by ldauga           ###   ########lyon.fr    #
# #                                                                              #
# # **************************************************************************** #

NAME			=	cub3D

MINILIBX		=	libmlx.a
LIB				=	libft/libft.a

SRCS			=	srcs/cub_3d.c
GENERATE_SRCS	=	srcs/map_for_cub/map_for_cub_1.c \
					srcs/map_for_cub/map_for_cub_2.c
OBJS			=	${SRCS:.c=.o}
GENERATE_OBJS	=	${GENERATE_SRCS:.c=.o}

INCLUDES		=	./incs

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -O3 -g3

all:	compilation $(NAME)

compilation:
		@make -C libft
		@make -C mlx

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -I $(INCLUDES) $(LIB) $(OBJS) -o $(NAME)
			@cp mlx/libmlx.dylib .

generate:	compilation $(GENERATE_OBJS)
				@$(CC) $(CFLAGS) -I $(INCLUDES) $(LIB) $(GENERATE_OBJS) -o generate_map
				@./generate_map $(X) $(Y) >> maps/generated_map.cub
				@rm -rf ./generate_map

gcc_not_flag:	$(OBJS)
				@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -I $(INCLUDES) $(LIB) $(OBJS) -o $(NAME)
				@cp mlx/libmlx.dylib .
				@./Cub3D maps/map_subject.cub

sanitize:	$(OBJS)
			@$(CC) -Lmlx -lmlx -g3 -fsanitize=address -framework OpenGL -framework AppKit $(CFLAGS) -I $(INCLUDES) $(LIB) $(OBJS) -o $(NAME)
			@cp mlx/libmlx.dylib .

lldb:	$(OBJS)
			@$(CC) -Lmlx -lmlx -g -framework OpenGL -framework AppKit $(CFLAGS) -I $(INCLUDES) $(LIB) $(OBJS) -o $(NAME)
			@cp mlx/libmlx.dylib .
clean:
		@make -C libft clean
		@rm -f $(OBJS)

norme:
		@norminette srcs/${SRCS_NAME}

fclean:	clean
		@make -C libft fclean
		@rm -f $(NAME) $(GENERATE_OBJS)

generate_map_re: fclean generate

re:	fclean all

.PHONY:	all fclean clean re norme
