NAME		=	philo
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I./
SRCS		=	main.c

OBJS		=	$(addprefix ./, ${SRCS:.c=.o})
RM			=	@rm -rf

$(NAME)		=	${OBJS}

all			:	${NAME}

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

re			:	fclean
				all

.PHONY		:	all clean fclean re