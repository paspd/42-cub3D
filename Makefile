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

SRCS			=	srcs/cub_3d.c \
					srcs/init.c \
					srcs/init_texture_img.c \
					srcs/parsing_texture.c \
					srcs/parsing_map_1.c \
					srcs/parsing_map_2.c \
					srcs/parsing_color.c \
					srcs/aff.c \
					srcs/arrow.c \
					srcs/full_map.c \
					srcs/mini_map.c \
					srcs/move.c \
					srcs/raycast.c \
					srcs/screen_shoot.c \
					srcs/aff_sprite.c \
					srcs/check_key.c \
					srcs/draw.c \
					srcs/parsing.c \
					srcs/check.c \
					srcs/exit.c
GENERATE_SRCS	=	srcs/mfc/map_for_cub.c \
					srcs/mfc/map_for_cub_utilis.c
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
