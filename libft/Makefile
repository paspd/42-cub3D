ERASE	=	\033[2K\r
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PINK	=	\033[35m
CYAN	=	\033[36m
ORANGE	=	\033[38;5;166m
PURPLE	=	\033[38;5;128m
WHITE	=	\033[37m
END		=	\033[0m
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m

HEADER		=	incs/libft.h

SRCS_PATH	=	srcs

SRCS_SUP	=	.obj/convert \
				.obj/files \
				.obj/ft_is \
				.obj/ft_mem \
				.obj/ft_str \
				.obj/ft_to \
				.obj/gnl \
				.obj/list \
				.obj/malloc \
				.obj/write \
				.obj/other


OBJS_PATH	=	.obj

SRCS_FILES	=	convert/ft_atoi.c \
				convert/ft_itoa.c \
				convert/ft_convert_base.c \
				convert/ft_convert_base_utilis.c \
				ft_is/ft_isalnum.c \
				ft_is/ft_isalpha.c \
				ft_is/ft_isascii.c \
				ft_is/ft_isdigit.c \
				ft_is/ft_isprint.c \
				ft_is/ft_ischar.c \
				ft_mem/ft_memset.c \
				ft_mem/ft_memcpy.c \
				ft_mem/ft_memccpy.c \
				ft_mem/ft_memmove.c \
				ft_mem/ft_memchr.c \
				ft_mem/ft_memcmp.c \
				ft_to/ft_tolower.c \
				ft_to/ft_toupper.c \
				malloc/ft_bzero.c \
				malloc/ft_calloc.c \
				ft_str/ft_strlcat.c \
				ft_str/ft_strcat.c \
				ft_str/ft_strlen.c \
				ft_str/ft_strncmp.c \
				ft_str/ft_strlcpy.c \
				ft_str/ft_strchr.c \
				ft_str/ft_strnchr.c \
				ft_str/ft_strrchr.c \
				ft_str/ft_strnstr.c \
				ft_str/ft_strdup.c \
				ft_str/ft_substr.c \
				ft_str/ft_strjoin.c \
				ft_str/ft_strtrim.c \
				ft_str/ft_split.c \
				ft_str/ft_strmapi.c \
				ft_str/ft_strcmp.c \
				write/ft_putchar_fd.c \
				write/ft_putstr_fd.c \
				write/ft_putnbr_fd.c \
				write/ft_putendl_fd.c \
				write/ft_putchar.c \
				write/ft_putchar_color.c\
				write/ft_putstr.c \
				write/ft_putnbr.c \
				write/ft_putstr_color.c \
				list/ft_lstadd_back.c \
				list/ft_lstadd_front.c \
				list/ft_lstclear.c \
				list/ft_lstdelone.c \
				list/ft_lstiter.c \
				list/ft_lstlast.c \
				list/ft_lstmap.c \
				list/ft_lstnew.c \
				list/ft_lstsize.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				files/ft_open_files.c \
				files/ft_close_files.c \
				other/ft_rand_in_range.c \
				other/ft_rand_percent.c

OBJS_FILES	=	${SRCS_FILES:.c=.o}

SRCS		=	$(addprefix $(SRCS_PATH)/,$(SRCS_FILES))

OBJS		=	$(addprefix $(OBJS_PATH)/,$(OBJS_FILES))

FLAGS		=	-Werror -Wall -Wextra

NAME		=	libft.a

INCS		=	libft.h

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c $(HEADER)
	@mkdir -p $(OBJS_PATH) $(SRCS_SUP)
	@gcc ${FLAGS} -I ${INCS} -c $< -o $@ -D BUFFER_SIZE=1
	@printf "$(YELLOW)$(BOLD)$(ERASE)COMPILING: $(END) $(RED)$<$(END)"

all:	${NAME}

${NAME}:	${OBJS}
	@ar rc ${NAME} $(OBJS)
	@printf "$(ERASE)"
	@printf "$(ERASE)$(RED)▓$(ORANGE)▓$(YELLOW)▓$(GREEN)▒$(BLUE)▒$(PURPLE)░░$(GREEN)$(BOLD)[LIBFT.A GENERATED]$(END)$(PURPLE)░░$(BLUE)▒$(GREEN)▒$(YELLOW)▓$(ORANGE)▓$(RED)▓\n$(END)"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(BOLD)$(GREEN)[CLEAN DONE]$(END)"

fclean:	clean
	@rm -rf ${NAME}
	@printf "$(GREEN)$(BOLD)[FCLEAN DONE]\n$(END)"

re:	fclean all

.PHONY:	re clean all fclean