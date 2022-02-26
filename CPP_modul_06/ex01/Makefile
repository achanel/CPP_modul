NAME	=	Serialization

CC		=	c++
CFLAGS	=	-std=c++98 -Wall -Wextra -Werror -g
RM		=	rm -f

HEAD	=	$(wildcard *.hpp)
SRCS	=	$(wildcard *.cpp)
OBJS	=	$(SRCS:.cpp=.o)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS) $(HEAD)
			$(CC) $(OBJS) -o $(NAME)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re