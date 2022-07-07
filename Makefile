NAME		=	./philo/philo
NAMEB		=	./philo_bonus/philo_bonus
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra $(EXTRAF)
EXTRAF		=	-g -pthread
INCLUDES	=	-I./philo
INCLUDESB	=	-I./philo_bonus/
SRCS		=	main.c\
				structure.c \
				msg.c \
				parssing.c \
				routine.c \
				state.c \
				utils.c
OBJS		=	$(addprefix ./philo/, ${SRCS:.c=.o})
OBJSB		=	$(addprefix ./philo_bonus/, ${SRCS:.c=.o})
RM			=	@rm -rf

$(NAME)		:	${OBJS}
				${CC} ${FLAGS} ${INCLUDES} ${OBJS} -o $@
				@cp ${NAME} ./

$(NAMEB)	:	${OBJSB}
				${CC} ${FLAGS} ${INCLUDESB} ${OBJSB} -o $@
				@cp ${NAMEB} ./

all			:	${NAME} ${NAMEB}

clean		:
				${RM} ${OBJSB}
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAMEB}
				${RM} ${NAME}
				

re			:	fclean all

bonus		:	${NAMEB}

.PHONY		:	${NAMEB} all clean fclean re