NAME	=	FragTrap
CC		=	c++
CFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM		=	rm -f

HEAD	=	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
SRCS	=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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