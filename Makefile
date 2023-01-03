CC = cc
NAME = fdf
ODIR = obj
BDIR = bin
LDIR = lib
LIBFT = $(LDIR)/libft
LIBMLX = $(LDIR)/mlx
RM = rm -f
CFLAGS = -Wall -Wextra
LFLAGS = -L$(LIBFT) -lft -L$(LIBMLX) -lmlx -lXext -lX11 -lm
_OBJS =  main.o display.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: lib $(NAME)

$(ODIR)/%.o : src/%.c 
	$(CC) -Wall -Wextra $(LIBMLX)/libmlx.a  -O3 -c $< -o $@

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


