NAME	=	Animal

CC		=	c++
CFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM		=	rm -f

HEAD	=	Animal.hpp Dog.hpp Cat.hpp
SRCS	=	main.cpp Animal.cpp Dog.cpp Cat.cpp
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