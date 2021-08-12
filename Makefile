NAME		= cub3D

C_FLAG		= -Wall -Wextra -Werror

DIR_SRC		= src/
DIR_OBJ		= bin/

INCLUDES	= includes
LIBMLX_PATH	= minilibx_mms
LIBFT_PATH	= libft

LIBMLX		= libmlx.dylib
LIBFT		= libft.a
#VPATH		= src bin includes

HEADERS		:= cub3d.h

SRC			:= \
			\
			main.c					\
			parser.c				\
			parser_utils.c			\
			parser_utils2.c			\
			keypress.c				\
			keypress_utils.c		\
			sprite.c				\
			draw_utils.c			\
			draw_karta.c			\
			cub_utils.c				\
			cub_utils1.c			\
			sshot.c					\


OBJ			:= $(SRC:c=o)
DEBUG_OBJ	:= $(SRC:c=o)

SRC			:= $(addprefix $(DIR_SRC), $(SRC))
OBJ			:= $(addprefix $(DIR_OBJ), $(OBJ))

$(DIR_OBJ)%.o:		$(DIR_SRC)%.c $(INCLUDES)/$(HEADERS)
	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)

all:			$(LIBFT) $(NAME)

$(NAME):		$(OBJ)
	$(MAKE) -C $(LIBMLX_PATH)
	mv $(LIBMLX_PATH)/$(LIBMLX) .
	gcc $(C_FLAG) $^ -L. -lft -Llibft -lmlx -framework OpenGL -framework AppKit -o $(NAME)


$(LIBFT):
	mkdir -p bin
	$(MAKE) -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ)

fclean:			clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -f $(LIBMLX)
	rm -f $(NAME)

re:	fclean all

.PHONY:			clean fclean re
