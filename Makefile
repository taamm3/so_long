SRCS = main.c\
		so_long.c \
		draw.c \
		map.c\
		move.c\
		pixel.c\
		utils.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = gcc

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${MLXFLAG} libmlx.dylib ${SRCS} -o ${NAME}

clean : 
	${RM} ${OBJS}

fclean : clean
	 ${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re