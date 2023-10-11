# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:08:34 by tgibier           #+#    #+#              #
#    Updated: 2023/10/11 14:23:22 by tgibier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Das Progamm
NAME			=	cub3d

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
SRCS_PATH		=	src
SRCS_NAMES		=	main.c

SRCS			=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAMES))
					
# Objects
OBJS_PATH		=	obj
OBJS_NAMES		=	$(SRCS_NAMES:.c=.o)
OBJS			=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

# -fsanitize=address

MAKEFLAGS		=	--no-print-directory

all	:	$(MLX) $(LIBFT) ${NAME}

$(OBJS_PATH)/%.o	: $(SRCS_PATH)/%.c
		@mkdir -p $(OBJS_PATH)
		@printf "$(_FOREST_GREEN)🛸 Preparing for landing... %-50s \r" $@
		@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)
		@echo "$(_EMMERALD)Cub3D: .obj/ folder created$(_END)"

$(LIBFT)	:
		@echo "$(_GOLD)Summoning libft's genie$(_END)"
		@make -sC $(LIBFT_PATH)

$(MLX)		: 
		@echo "Crafting MiniLibX"
		@make -sC $(MLX_PATH)

$(NAME) 	: $(OBJS) $(LIBFT) $(MLX)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(LDFLAGS) $(MLXFLAGS)
		@echo "\n 👾$(_FOREST_GREEN)$(_BOLD) DOWN THE RABBIT HOLE, WOOP WOOP $(_END)👾"

clean:
	@echo "$(_AQUAMARINE) Which potion will it be ? $(_END)"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	

fclean:	clean
	@echo "$(_AQUAMARINE)$(_BOLD)🚀 Leaving Wonderland 🚀$(_END)"
	@rm -rf $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re