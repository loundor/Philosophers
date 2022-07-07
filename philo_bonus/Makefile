NAME		=	philo_bonus
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra $(EXTRAF)
EXTRAF		=	-g -pthread
INCLUDES	=	-I./
SRCS		=	structure.c \
				msg.c \
				parssing.c \
				routine.c \
				state.c \
				utils.c
SRCN		=	${SRCS} main.c
OBJS		=	$(addprefix ./, ${SRCN:.c=.o})
RM			=	@rm -rf

$(NAME)		:	${OBJS}
				${CC} ${FLAGS} ${INCLUDES} ${OBJS} -o $@

all			:	${NAME}

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re