# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 16:15:58 by sakitaha          #+#    #+#              #
#    Updated: 2025/01/13 20:05:18 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM       := rm -f
TARGET   := convert
SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

test: $(TARGET)
	@echo "== Running Tests  =="
	./$(TARGET) 0
	./$(TARGET) nan
	./$(TARGET) 42.0f
	@echo "== Tests Completed =="

testc: $(TARGET)
	@echo "== Running char Tests =="
	./$(TARGET) 'c'
	./$(TARGET) 'a'
	@echo "== Tests Completed =="

testi: $(TARGET)
	@echo "== Running int Tests =="
	./$(TARGET) 0
	./$(TARGET) -42
	./$(TARGET) 42
	./$(TARGET) -2147483648
	./$(TARGET) 2147483647
	./$(TARGET) -2147483649
	./$(TARGET) 2147483648
	@echo "== Tests Completed =="

testf: $(TARGET)
	@echo "== Running float Tests =="
	./$(TARGET) 0.0f
	./$(TARGET) -4.2f
	./$(TARGET) 4.2f
	./$(TARGET) -inff
	./$(TARGET) +inff
	@echo "== Tests Completed =="

testd: $(TARGET)
	@echo "== Running double Tests =="
	./$(TARGET) 0.0
	./$(TARGET) -4.2
	./$(TARGET) 4.2
	./$(TARGET) -inf
	./$(TARGET) +inf
	./$(TARGET) nan
	@echo "== Tests Completed =="

teste: $(TARGET)
	@echo "== Running double Tests =="
	./$(TARGET) 1e+300
	./$(TARGET) -1e-300
	./$(TARGET) 123abc
	./$(TARGET) ++42
	./$(TARGET) 0
	./$(TARGET) 127
	@echo "== Tests Completed =="

testall: re test testc testi testf testd

debug: CXXFLAGS += -fsanitize=address -g
debug: $(TARGET)
	./$(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean fclean re debug leaks valgrind test testc testi testf testd teste testall
