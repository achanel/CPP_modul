NAME	=	bsp

CC		=	c++
CFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM		=	rm -f

HEAD	=	Fixed.hpp Point.hpp
SRCS	=	main.cpp Fixed.cpp Point.cpp bsp.cpp
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