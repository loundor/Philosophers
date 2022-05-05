NAME		=	philo
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra $(EXTRAF)
EXTRAF		=	-g -pthread
INCLUDES	=	-I./
SRCS		=	main.c \
				structure.c \
				parssing.c \
				routine.c \
				state.c \
				utils.c

OBJS		=	$(addprefix ./, ${SRCS:.c=.o})
RM			=	@rm -rf

$(NAME)		:	${OBJS}
				${CC} ${FLAGS} ${OBJS} -o $@

all			:	${NAME}

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re