CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert

SRCS = ScalarConverter.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

Headers = ScalarConverter.hpp

all: $(NAME)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(Headers)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re