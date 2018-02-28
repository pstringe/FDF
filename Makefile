# name
NAME = fdf

# directories
SRCD = ./srcs/
INCD = ./includes/
OBJD = ./objs/

# srcs
SRCS = ./srcs/first.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

# compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
OFLAGS =  -o $(NAME) $(OBJS) $(LIBD)

# libraries
# mlx
MLX = minilibx/
MLX_LIB = $(addprefix $(MLX), mlx.a)
MLX_INC = -I $(MLX)
MLX_LNK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit

# libft
FT = libft/
FT_LIB = $(addprefix $(FT), libft.a)
FT_INC = -I $(FT)
FT_LNK = -L $(FT) -l ft

# rules
all : objs $(FT_LIB) $(MLX_LIB) $(NAME)

objs :
	mkdir -p $(OBJD)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -c $(SRCS)

$(FT_LIB) :
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJD)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(DNAME)
	rm -rf $(DNAME).dSYM

re: fclean
	make

debug : all
	lldb $(NAME) $(DARGS)
