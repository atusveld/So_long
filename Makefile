# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: atusveld <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/08 15:54:56 by atusveld      #+#    #+#                  #
#    Updated: 2023/02/16 19:10:38 by atusveld      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long

SRC			=		main.c\
					src/init.c\
					src/read_map.c\
					src/check_map.c\
					src/hook.c

DR_SRC		=		src/
DR_INC		=		inc/
DR_LIBFT	=		Libft/
DR_MLX		=		MLX42/

MLX			=		MLX42/build/libmlx42.a
LIBFT		=		Libft/libft.a

CFLAGS		=		-Wall -Wextra -Werror
CFLAGS		+=		-g -fsanitize=address
LFLAGS		=		-ldl -lglfw -pthread -lm
#MLXFLAGS	=		-ldl -lglfw -pthread -lm

INC			=		-IMLX42/include/MLX42/ -ILibft/ -Iinc/
OBJ			=		$(SRC:.c=.o)

CC			=		cc

all:
	@$(MAKE) $(NAME) -j4 --no-print-directory

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@cc $(OBJ) $(LIBFT) $(MLX) $(CFLAGS) $(INC) $(LFLAGS) -o $(NAME)
	@echo "- [SO_LONG COMPILED]"

%.o:		%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C Libft --no-print-directory

clean:
	@rm -f $(OBJ)
	@make clean -C Libft --no-print-directory

fclean:		clean
	@rm -f $(OBJ)
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "- [SO_LONG CLEAN]"
	@echo "- [LIBFT CLEAN]"

re:			fclean all
	@echo "- [SO_LONG REBUILT]"

.PHONY: all clean fclean re
