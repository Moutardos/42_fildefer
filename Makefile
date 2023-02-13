CC = cc
NAME = fdf
ODIR = obj
BDIR = bin
IDIR = include
LIBFT = $(IDIR)/libft
LIBMLX = $(IDIR)/mlx
RM = rm -f
CFLAGS = -Wall -Wextra -I$(IDIR) -g 
LFLAGS = -L$(LIBFT) -lft -L$(LIBMLX)   -lmlx -lXext -lX11 -lm
_DEPS = event.h display.h grid.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJS =  main.o display.o grid.o utils.o display_utils.o event.o keys.o matrice.o transform.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: lib $(NAME)

$(ODIR)/%.o : src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

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

malloc_test: lib $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} $(LFLAGS) -L. -lmallocator 