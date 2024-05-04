NAME = cube3d

FILES = raycaster.c

CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(FILES:.c=.o)
RM = rm -rf

all: $(NAME)

# $(NAME): ${OBJS}
# 	${CC} $(OBJS) -o $(NAME) $(MLX)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all