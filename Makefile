NAME		=	philo
NAMEB		=	philo_bonus
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra $(EXTRAF)
EXTRAF		=	-g -pthread
INCLUDES	=	-I./
INCLUDESB	=	-I./philo_bonus/
SRCS		=	structure.c \
				msg.c \
				parssing.c \
				routine.c \
				state.c \
				utils.c
SRCN		=	${SRCS} main.c
SRCB		=	${SRCS} main_bonus.c
OBJS		=	$(addprefix ./, ${SRCN:.c=.o})
OBJSB		=	$(addprefix ./philo_bonus/, ${SRCB:.c=.o})
RM			=	@rm -rf

$(NAME)		:	${OBJS}
				${CC} ${FLAGS} ${INCLUDES} ${OBJS} -o $@

$(NAMEB)	:	${OBJSB}
				${CC} ${FLAGS} ${INCLUDESB} ${OBJSB} -o $@

all			:	${NAME}

clean		:
				${RM} ${OBJS} ${OBJSB}

fclean		:	clean
				${RM} ${NAME}
# WARNING!! remove the folder!!
# @${RM} ${NAMEB}

re			:	fclean all

bonus		:	${NAMEB}

.PHONY		:	${NAMEB} all clean fclean re