CC = cc
ODIR = obj
BDIR = bin
IDIR = include
NAME = $(BDIR)/fdf
LIBFT = $(IDIR)/libft/libft.a
LIBMLX = $(IDIR)/mlx/libmlx.a
LIB = $(LIBFT)/libft.a

RM = rm -f
CFLAGS = -Wall -Wextra -I$(IDIR) -g 
LFLAGS = -L$(IDIR)/libft -lft -L$(IDIR)/mlx -lmlx -lXext -lX11 -lm
_DEPS = event.h display.h grid.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJS =  main.o display.o grid.o utils.o display_utils.o event.o keys.o matrice.o transform.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: $(LIBFT) $(LIBMLX) | $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(BDIR):
	mkdir -p $(BDIR)

$(LIBFT):
	$(MAKE) -C $(IDIR)/libft

$(LIBMLX):
	$(MAKE) -C $(IDIR)/mlx

$(ODIR)/%.o : src/%.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) | $(BDIR)
	$(CC) $(CFLAGS)  -o  $@ $(OBJS) $(LFLAGS)

clean:
	$(RM) -R $(ODIR)
	$(MAKE) -C $(IDIR)/libft $@
	$(MAKE) -C $(IDIR)/mlx $@

fclean: clean
	$(MAKE) -C $(IDIR)/libft $@
	$(RM) -R $(BDIR)

re: fclean all

.PHONY: all clean fclean re lib