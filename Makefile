NAME			=	cub3d

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I $(HEADER_DIR) -I $(LIBFT_DIR)
RM				=	rm -rf

SRC_DIR			=	src

SRC				=	\
					main.c \
					parsing/blank_lines.c \
					parsing/reader.c \
					parsing/split_lines.c \
					parsing/parse_color.c \
					parsing/parse_headers.c \
					parsing/build_map.c \
					validation/validate_map.c \
					validation/validate.c \
					validation/validate_closed.c \
					error_exit/exit.c
					

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))

HEADER_DIR		=	includes
HEADERS			=	$(wildcard $(HEADER_DIR)/*.h)

OBJ_DIR			=	obj
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# **************************************************************************** #

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) all

# **************************************************************************** #

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:			clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
