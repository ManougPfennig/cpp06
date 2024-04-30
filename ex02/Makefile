NAME =	Identify
SRCS =	main.cpp Base.cpp A.cpp B.cpp C.cpp
FLAGS =	-std=c++98 -Wall -Wextra -Werror

OBJS = ${SRCS:.cpp=.o}

${NAME}: ${OBJS}
	c++  ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all