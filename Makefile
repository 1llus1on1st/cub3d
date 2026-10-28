NAME			=	cub3d

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I $(HEADER_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
RM				=	rm -rf

SRC_DIR			=	src

SRC				=	\
					main.c \
					error_exit/exit.c \
					game/hooks.c \
					game/init.c \
					game/pixel.c \
					game/player.c \
					parsing/blank_lines.c \
					parsing/build_map.c \
					parsing/parse_color.c \
					parsing/parse_headers.c \
					parsing/reader.c \
					parsing/split_lines.c \
					render/ray_init.c \
					render/raycast.c \
					validation/validate_closed.c \
					validation/validate_map.c \
					validation/validate.c
					

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))

HEADER_DIR		=	includes
HEADERS			=	$(wildcard $(HEADER_DIR)/*.h)

OBJ_DIR			=	obj
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

MLX_DIR			=	./minilibx_opengl_20191021
MLX				=	$(MLX_DIR)/libmlx.a

MLX_FLAGS		=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

# **************************************************************************** #

$(MLX):
	make -C $(MLX_DIR) all

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
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:			clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
