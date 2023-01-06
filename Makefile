CC = cc
NAME = fdf
ODIR = obj
BDIR = bin
LDIR = lib
LIBFT = $(LDIR)/libft
LIBMLX = $(LDIR)/mlx
LIBMLX_MAC = $(LDIR)/mlx_mac
RM = rm -f
CFLAGS = -Wall -Wextra
LFLAGS = -L$(LIBFT) -lft -L$(LIBMLX) -lmlx -lXext -lX11 -lm
LFLAGS_MAC = -L$(LIBFT) -lft -L$(LIBMLX_MAC) -lmlx  -framework OpenGL -framework AppKit -o $(NAME)

_OBJS =  main.o display.o grid.o utils.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: lib $(NAME)

$(ODIR)/%.o : src/%.c 
	$(CC) -Wall -Wextra $(LIBMLX_MAC)/libmlx.a  -O3 -c $< -o $@

lib:
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(LIBMLX_MAC)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS)  -o  $(BDIR)/$@ $(OBJS) $(LFLAGS_MAC)

clean:
	$(RM) -R $(ODIR)
	$(MAKE) -C $(LIBFT) $@
	$(MAKE) -C $(LIBMLX_MAC) $@

fclean: clean
	$(MAKE) -C $(LIBFT) $@
	$(RM) -R $(BDIR)

re: fclean all

.PHONY: all clean fclean re lib


