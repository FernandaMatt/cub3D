NAME		:=	cub3D	
NAME_BONUS	:=	cub3D_bonus
##MAKEFLAGS	:= --silent

####	Compilers & flags	####
CC		:=	cc
CFLAGS	:=	-g -Wextra -Wall -Werror

####	Directories	####
SRCDIR	:=	source/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	libft/
LISTDIR 	:=	color texture game interpretate_map validate_map	engine

####	Sources & objects	####

MAIN				:=	main	setup	aux	render_game	transform_map free
MAIN_BONUS			:=	main	setup	aux	render_game_bonus	transform_map free
INTERPRETATE_MAP	:=	interpretate_map		auxiliar
COLOR				:=	get_color	checkers
TEXTURE				:=	get_texture	cardinal_points
VALIDATE_MAP		:=	validate_map	validate_player	validate_border	validate_char	\
						validate_up_down	validate_left_right	validate_middle
ENGINE				:=	draw  calculations	calculations_2	hooks	\
						render_map	bresenham	render	hooks2
ENGINE_BONUS		:=	draw  calculations	calculations_2	hooks	\
						render_map	render_map_bonus bresenham	render	hooks

SRC		:=	$(MAIN)	\
			$(addprefix interpretate_map/, $(INTERPRETATE_MAP))	\
			$(addprefix validate_map/, $(VALIDATE_MAP))	\
			$(addprefix color/, $(COLOR))	\
			$(addprefix texture/, $(TEXTURE))	\
			$(addprefix game/, $(GAME))			\
			$(addprefix engine/, $(ENGINE))

SRC_BONUS	:=	$(MAIN_BONUS)	\
			$(addprefix interpretate_map/, $(INTERPRETATE_MAP))	\
			$(addprefix validate_map/, $(VALIDATE_MAP))	\
			$(addprefix color/, $(COLOR))	\
			$(addprefix texture/, $(TEXTURE))	\
			$(addprefix game/, $(GAME))			\
			$(addprefix engine/, $(ENGINE_BONUS))

SRCS	:=	$(addsuffix .c, $(SRC))
OBJ		:=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

SRCS_BONUS :=	$(addsuffix .c, $(SRC_BONUS))
OBJ_BONUS  :=	$(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.o))

####	Libft		####
LIBLIB		:=	$(LIBDIR)libft.a

####	defining OS name variable	####
UNAME := $(shell uname)

#----------------- mlx library  for mac ---------------
ifeq ($(UNAME), Darwin)
	MLX		:= ./miniLibX/
	MLX_LIB	:= $(addprefix $(MLX), libmlx.a	)
	MLX_INC	:= -I ./miniLibX
	MLX_LNK	:= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit
endif

#----------------- mlx library  for linux ---------------
ifeq ($(UNAME), Linux)
	MLX		:= ./mlx_linux
	MLX_LIB	:= $(addprefix $(MLX), mlx.a)
	MLX_INC	:= -Imlx_linux -O3
	MLX_LNK	:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

# Colors
BLACK	=	\033[0;30m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
MAGENTA	=	\033[1;35m
ORANGE	=	\033[1;38;5;214m
RED		=	\033[0;31m
RESET	=	\033[0m
WHITE	=	\033[0;37m
YELLOW	=	\033[0;33m

######	Commands	######

all:	obj $(MLX_LIB) $(LIBLIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(addprefix $(OBJDIR), $(LISTDIR))

bonus: obj $(MLX_LIB) $(LIBLIB) $(NAME_BONUS)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(LIBLIB) $(LINK) -o $@
	@echo "cub3D created"

$(LIBLIB):
	@make -C $(LIBDIR) all
	@echo "libf lib created"

$(MLX_LIB):
	make -C $(MLX)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(MLX_LNK) $(LIBLIB) $(LINK) -o $@
	@echo "cub3D bonus created"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean
	@echo "I deleted everything"

fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "I deleted even the deletion"

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./${NAME}

.PHONY: re, fclean, clean, all

#$(shell echo '$@ <- Nome da regra.')
#$(shell echo '$< <- Nome da primeira dependência.')
#$(shell echo '$^ <- Lista de dependências.')
#$(shell echo '$? <- Lista de dependências mais recentes que a regra.')
#$(shell echo '$* <- Nome do arquivo sem sufixo.')
