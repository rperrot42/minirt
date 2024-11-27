MAKE = make

NAME = miniRT

LIBFT = libft/libft.a

DIR_OBJS = .obj

INCLUDE_DIR = includes

OS := $(shell uname)

LIBFT_DIRECTORY = ./libft/

FLAGS = -Wall -Werror -Wextra -g3

DFLAGS = -MD -MP

INCLUDE = $(INCLUDE_DIR)/mini_rt.h

SRC_ERROR = 	error.c			\
				free_scene.c	\


SRC_PARSING =	check_file.c	\
				get_info_line.c	\
				add_element.c	\
				readline.c		\
				add_ambient.c	\
				add_camera.c	\
				add_cylinder.c	\
				add_light.c		\
				add_plane.c		\
				add_sphere.c	\

SRC_COLLISION = plane.c			\
				sphere.c		\
				shadow.c		\

SRC_ANGLE = 	create_line.c	\
				scalar_product.c

SRC_INIT =		init_mlx.c		\

SRC_OBJECT =	move.c

ifeq ($(OS), Darwin)
	SRC_INIT += mlx_destroy_display.c
endif

SRC_COLOR =		color.c			\

SRC_MLX =		pixel_put.c		\
				hooking.c		\

SRC =	$(addprefix parsing/, $(SRC_PARSING))		\
		$(addprefix error/, $(SRC_ERROR))			\
		$(addprefix collision/, $(SRC_COLLISION))	\
		$(addprefix angle/, $(SRC_ANGLE))			\
		$(addprefix init/, $(SRC_INIT))				\
		$(addprefix color/, $(SRC_COLOR))			\
		$(addprefix mlx_functions/, $(SRC_MLX))		\
		$(addprefix object/, $(SRC_OBJECT))			\
		main.c										\

SRC_PATH = src/

CC = cc

CHECK = ✅
RED = $(shell tput setaf 1)
CROSS = ❌
GREEN = $(shell tput setaf 2)
RESET_COLOR = $(shell tput sgr0)
CYAN = $(shell tput setaf 6)

OS := $(shell uname)

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))
DEP = $(OBJ:.o=.d)

all:$(NAME)

IFLAGS =	-Ilibft/includes			\
			-I$(INCLUDE_DIR)			\
			-I$(INCLUDE_DIR)/parsing	\
			-I$(INCLUDE_DIR)/collision	\
			-I$(INCLUDE_DIR)/angle		\
			-I$(INCLUDE_DIR)/init		\
			-I$(INCLUDE_DIR)/color		\

ifeq ($(OS), Linux)
	DIR_MLX = mlx_linux
else
	DIR_MLX = mlx_macos
endif

-include $(DEP)

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c Makefile
	@mkdir -p  $(dir $@)
ifeq ($(OS), Linux)
	@$(CC)  $(IFLAGS) $(FLAGS) $(DFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
	@$(CC)  $(IFLAGS) $(FLAGS) $(DFLAGS) -Imlx_macos -c $< -o $@
endif
	@echo "$(CYAN)$@ created $(CHECK)$(RESET_COLOR)"

$(NAME): $(OBJ) $(LIBFT) mlx
ifeq ($(OS), Linux)
	@$(CC) $(OBJ)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)
else
	@$(CC) $(OBJ) -Lmlx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
endif
	@echo "$(GREEN)$(NAME) created $(CHECK)$(RESET_COLOR) "

clean:
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -C $(LIBFT_DIRECTORY) clean
	@$(MAKE) -C $(DIR_MLX) clean
	@echo "$(RED)$(DIR_OBJS) removed $(CROSS)$(RESET_COLOR) "

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIRECTORY)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed $(CROSS)$(RESET_COLOR) "

mlx: FORCE
	@$(MAKE) -C $(DIR_MLX)

FORCE:

re: fclean all

.PHONY: all re clean fclean re FORCE
