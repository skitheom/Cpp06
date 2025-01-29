# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 16:15:58 by sakitaha          #+#    #+#              #
#    Updated: 2025/01/14 17:15:40 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM       := rm -f
NAME     := convert
SRCS     := ScalarConverter.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	@echo "== Running Tests  =="
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	@echo "== Tests Completed =="

testc: $(NAME)
	@echo "== Running char Tests =="
	./$(NAME) 'c'
	./$(NAME) 'a'
	@echo "== Tests Completed =="

testi: $(NAME)
	@echo "== Running int Tests =="
	./$(NAME) 0
	./$(NAME) -42
	./$(NAME) 42
	./$(NAME) -2147483648
	./$(NAME) 2147483647
	./$(NAME) -2147483649
	./$(NAME) 2147483648
	@echo "== Tests Completed =="

testf: $(NAME)
	@echo "== Running float Tests =="
	./$(NAME) 0.0f
	./$(NAME) -4.2f
	./$(NAME) 4.2f
	./$(NAME) -inff
	./$(NAME) +inff
	@echo "== Tests Completed =="

testd: $(NAME)
	@echo "== Running double Tests =="
	./$(NAME) 0.0
	./$(NAME) -4.2
	./$(NAME) 4.2
	./$(NAME) -inf
	./$(NAME) +inf
	./$(NAME) nan
	@echo "== Tests Completed =="

teste: $(NAME)
	@echo "== Running error Tests =="
	./$(NAME) 1e+300
	./$(NAME) -1e-300
	./$(NAME) 123abc
	./$(NAME) ++42
	./$(NAME) 0
	./$(NAME) 127
	@echo "== Tests Completed =="

testall: re test testc testi testf testd teste

debug: CXXFLAGS += -fsanitize=address -g
debug: $(NAME)
	./$(NAME) 42

valgrind: all
	valgrind --leak-check=full ./$(NAME) 42

.PHONY: all clean fclean re debug leaks valgrind test testc testi testf testd teste testall
