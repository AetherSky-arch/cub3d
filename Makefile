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

CFLAGS = -Wno-incompatible-pointer-types

NAME = cub3d

all: libft $(NAME)

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -Wno-incompatible-pointer-types -o $(NAME) $(OBJS) $(MINILIBX) -lm -L libft -lft

$(OBJDIR)/%.o : %.c
	mkdir -p $(dir $@)
	cc -g3 -Wall -Wextra -Werror -Wno-incompatible-pointer-types -o $@ -c $<

libft:
	cd libft ; make

clean:
	rm -rf $(OBJDIR)
	cd libft ; make clean

fclean: clean
	rm -rf $(NAME)
	cd libft ; make fclean

re: fclean all

.PHONY: all clean fclean re libft
