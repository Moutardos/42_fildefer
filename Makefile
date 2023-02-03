CC = cc
NAME = fdf
ODIR = obj
BDIR = bin
IDIR = include
LIBFT = $(IDIR)/libft
LIBMLX = $(IDIR)/mlx
LIBMLX_MAC = $(IDIR)/mlx_mac
RM = rm -f
CFLAGS = -Wall -Wextra -I$(IDIR) $(LIBMLX)/libmlx.a 
LFLAGS = -L$(LIBFT) -lft -L$(LIBMLX)   -lmlx -lXext -lX11 -lm
LFLAGS_MAC = -L$(LIBFT) -lft -L$(LIBMLX) -lmlx  -framework -OpenGL -framework AppKit -o $(NAME)

_DEPS = event.h display.h grid.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJS =  main.o display.o grid.o utils.o display_utils.o event.o keys.o matrice.o transform.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: lib $(NAME)

$(ODIR)/%.o : src/%.c 
	$(CC) $(CFLAGS)  -O3 -c $< -o $@

lib:
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(LIBMLX)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS)  -o  $(BDIR)/$@ $(OBJS) $(LFLAGS)

clean:
	$(RM) -R $(ODIR)
	$(MAKE) -C $(LIBFT) $@
	$(MAKE) -C $(LIBMLX) $@

fclean: clean
	$(MAKE) -C $(LIBFT) $@
	$(RM) -R $(BDIR)

re: fclean all

.PHONY: all clean fclean re lib


