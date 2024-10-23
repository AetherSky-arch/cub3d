SRCS = main.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	parsing/store_data.c \
	parsing/store_data_utils.c \
	parsing/check_argument.c \
	parsing/display_parsing.c \
	parsing/open_file.c \
	parsing/parsing_utils.c \
	parsing/parsing_utils2.c \
	parsing/store_textures.c \
	parsing/store_textures_utils.c \
	parsing/store_map.c \
	parsing/measure_map.c \
	parsing/find_player.c \
	parsing/check_text_id.c \
	parsing/check_text_dup.c \
	parsing/check_text_path.c \
	parsing/check_text_rgb.c \
	parsing/check_map_walls.c \
	parsing/check_map_size.c \
	parsing/check_map_character.c \
	parsing/check_map_players.c \
	parsing/check_map_line.c \
	raycasting/raycasting.c \
	raycasting/draw_wall.c \
	raycasting/get_texture.c \
	raycasting/put_pixel.c \
	raycasting/store_textures.c \
	raycasting/key_event.c \
	raycasting/draw_floor_ceiling.c \
	raycasting/init_values.c \
	ender.c


MINILIBX = ./minilibx/libmlx_Linux.a -lXext -lX11

OBJDIR = .obj

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

NAME = cub3d

all: libft mlx $(NAME)

mlx:
	@if ! test -d ./minilibx ; then echo "downloading minilibx from github.com/42Paris/minilibx-linux.git..."; fi
	@if ! test -d ./minilibx ; then git clone https://github.com/42Paris/minilibx-linux.git minilibx; fi
	@echo "compiling minilibx..." ; cd minilibx ; ./configure

$(NAME): $(OBJS)
	@cc -Wall -Wextra -Werror -o $(NAME) $(OBJS) $(MINILIBX) -lm -L libft -lft
	@echo "\nDone!"

$(OBJDIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@cc -g3 -Wall -Wextra -Werror -o $@ -c $<

libft:
	@if test -f libft/libft.a; then echo "Building Libft..." ; fi
	@cd libft ; make
	@echo "\n"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)
	@echo "Done!\n"
	@cd minilibx ; make clean
	@echo ""
	@cd libft ; make clean

fclean: clean
	@echo "Deleting binary..."
	@rm -f $(NAME)
	@echo "Done!\n"
	@cd libft ; make fclean

re: fclean all

.PHONY: all clean fclean re libft
