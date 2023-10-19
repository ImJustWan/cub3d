
-include mk/includes.mk
-include mk/sources.mk
-include mk/colors.mk

# Das Progamm
NAME			=	cub3d
NAME_BONUS		=	bonus

# Compiler
CC				=	cc
CFLAGS			=	-g3 -Wall -Werror -Wextra -MMD
LDFLAGS			=	-L $(LIBFT_PATH) -lft
MLXFLAGS		=	-lX11 -lXext -L $(MLX_PATH) -lmlx -lm

# Libft
LIBFT_PATH		=	libft/
LIBFT_NAME		=	libft.a
LIBFT			=	$(LIBFT_PATH)$(LIBFT_NAME)

# Minilibx
MLX_PATH		=	minilibx-linux/
MLX_NAME		=	libmlx.a
MLX				=	$(MLX_PATH)$(MLX_NAME)

HEAD			=	-I ./inc/ \
					-I ./libft/inc \
					-I ./minilibx-linux/ 

DEPS			=	${OBJS:.o=.d}

# Sources
SRCS_PATH		=	srcs/

# Objects
OBJS_PATH		=	objs/
OBJS_NAMES		=	$(SRCS:.c=.o)
OBJS			=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

# -fsanitize=address

MAKEFLAGS		=	--no-print-directory

all : ${NAME}

$(OBJS_PATH)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)
	@printf "$(_FOREST_GREEN)🐛 Falling asleep... %-50s \r" $@

$(OBJS_PATH) :
	@mkdir -p $(OBJS_PATH)
	@echo "$(_EMMERALD)Cub3D: .obj/ folder created$(_END)"

$(LIBFT) :
	@echo "$(_GOLD)Summoning libft's madhatter$(_END)"
	@make -sC $(LIBFT_PATH)

$(MLX) : 
	@echo "$(_LILAC)Crafting MiniLibX$(_END)"
	@make -sC $(MLX_PATH)

$(NAME) : $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LDFLAGS) $(MLX) $(MLXFLAGS)
	@echo "\n🐇$(_FOREST_GREEN)$(_BOLD) DOWN THE RABBIT HOLE WE GO $(_END)🐇"

clean:
	@echo "$(_AQUAMARINE)Which potion will it be ? $(_END)"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@make clean -C libft
	@make clean -C minilibx-linux
	
fclean:	clean
	@echo "$(_AQUAMARINE)$(_BOLD)🗝️ Leaving Wonderland 🎩$(_END)"
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@make fclean -C libft

re:	fclean all

cle: 
	@echo "$(_AQUAMARINE)Clearing Cub3d files $(_END)"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

cub: cle all

gmk:
		@if [ -d mk ];then echo ok;else mkdir mk;fi
		@find -path './src/*' -name '*.c' | sed 's/^/SRCS += /' > mk/sources.mk
		@find -path './inc/*' -name '*.h' | sed 's/^/INCLUDES += /' > mk/includes.mk

-include $(DEPS)

.PHONY:	all clean fclean re