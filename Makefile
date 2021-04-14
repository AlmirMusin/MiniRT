NAME		=	miniRT

LIBFT_DIR	=	./libft/
MLX_DIR		=	./mlx/

REND_DIR	=	./srcs/render/
PARSE_DIR	=	./srcs/parser/

LIBFT		=	libft.a
MLX			=	libmlx.dylib

HEADER		=	./includes/
LIB_HEADER	=	./libft/

SRCS		=	$(PARSE_DIR)check_id.c \
				$(PARSE_DIR)checks.c \
				$(PARSE_DIR)errors.c \
				$(PARSE_DIR)ft_atof.c \
				$(PARSE_DIR)get_next_line.c \
				$(PARSE_DIR)list_functions.c \
				$(PARSE_DIR)make_leaf.c \
				$(PARSE_DIR)objects.c \
				$(PARSE_DIR)parser.c \
				$(PARSE_DIR)frees.c \
				$(PARSE_DIR)square_points_compute.c \
				mini_rt.c \
				$(REND_DIR)camera_orientation.c \
				$(REND_DIR)compute_color.c \
				$(REND_DIR)create_image.c \
				$(REND_DIR)initialize.c \
				$(REND_DIR)intersections.c \
				$(REND_DIR)mlx_extentions.c \
				$(REND_DIR)pixel_data.c \
				$(REND_DIR)point_preparation.c \
				$(REND_DIR)vector_operations.c \
				$(REND_DIR)vector_operations2.c 

OBJS		=	$(SRCS:.c=.o)

GCC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit -lz

%.o:%.c		$(HEADER)mini_rt.h
			$(GCC) $(CFLAGS) -I$(HEADER) -c $< -o $@

all:		$(LIBFT) $(MLX) $(NAME)

$(LIBFT):	
			make -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)$(LIBFT) $(LIBFT)

$(MLX):		
			cp $(MLX_DIR)$(MLX) $(MLX)

$(NAME):	$(OBJS) 
			$(GCC) $(CFLAGS) $(MLX_FLAGS) -I$(HEADER) $(OBJS) -L. $(LIBFT) $(MLX) -o $(NAME)

clean:		
			make clean -C $(LIBFT_DIR)
			rm -rf $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			rm -rf $(NAME)
			rm -rf $(MLX)
			rm -rf $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
