MAKE = make

NAME = miniRt

LIBFT = libft/libft.a

DIR_OBJS = .obj

INCLUDE_DIR = includes

LIBFT_DIRECTORY = ./libft/

FLAGS = -Wall -Werror -Wextra

INCLUDE = $(INCLUDE_DIR)/mini_rt.h

SRC = test/main.c

SRC_PATH = src/

CC = cc

CHECK = ✅
RED = $(shell tput setaf 1)
CROSS = ❌
GREEN = $(shell tput setaf 2)
RESET_COLOR = $(shell tput sgr0)
CYAN = $(shell tput setaf 6)

OS := $(shell uname)

SYSTEM_EXPLOIT = uname

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)

IFLAGS = -Ilibft/includes \
			-I$(INCLUDE_DIR)

ifeq ($(OS), Linux)
	DIR_MLX = mlx_linux
else
	DIR_MLX = mlx
endif

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c Makefile $(INClUDE)
	@mkdir -p  $(dir $@)
ifeq ($(OS), Linux)
	@$(CC)  $(IFLAGS) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
	@$(CC)  $(IFLAGS) $(FLAGS) -Imlx -c $< -o $@
endif
	@echo "$(CYAN)$@ created $(CHECK)$(RESET_COLOR)"
$(NAME): $(OBJ) $(LIBFT) mlx
ifeq ($(OS), Linux)
	@$(CC) $(OBJ)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)
else
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
endif
	@echo "$(GREEN)$(NAME) created $(CHECK)$(RESET_COLOR)"

clean:
	@rm -rf $(DIR_OBJS)
	@echo "$(RED)$(DIR_OBJS) removed$(CROSS)$(RESET_COLOR)"
	@$(MAKE) -C $(LIBFT_DIRECTORY) clean
	@$(MAKE) -C $(DIR_MLX) clean

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIRECTORY)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(CROSS)$(RESET_COLOR)"

mlx: FORCE
	@$(MAKE) -C $(DIR_MLX)

FORCE:

re: fclean all

.PHONY: all re clean fclean re FORCE

