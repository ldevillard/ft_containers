NAME = ft_containers
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = includes/Vector.hpp
SRCS =	srcs/main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
		@clear
		@echo "\033[35m┌─┐┌┬┐   ┌─┐┌─┐┌┐┌┌┬┐┌─┐┬┌┐┌┌─┐┬─┐┌─┐\033[0m"
		@echo "\033[34m├┤  │    │  │ ││││ │ ├─┤││││├┤ ├┬┘└─┐\033[0m"
		@echo "\033[36m└   ┴────└─┘└─┘┘└┘ ┴ ┴ ┴┴┘└┘└─┘┴└─└─┘\033[0m"
		@echo "\033[34m_____________________________________\n\033[0m"
		@echo "\033[33m"
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)
		@echo "\033[0m"

$(NAME): $(OBJS) $(HEADER)
		@echo "\033[1m\033[36mLinking\033[0m"
		@echo "\033[33m"
		$(CC) -o $(NAME) $(OBJS)
		@echo "\033[0m"
		@mv srcs/*.o ./bin
		@echo "\033[1m\033[32mDone !\n\033[0m"

all : $(NAME)

clean :
		rm -rf bin/*.o
		@echo "\033[91m...\033[0m"

fclean : clean
		rm -rf $(NAME)
		@echo "\033[1m\033[31mCleaned\033[0m"

re : fclean all

.PHONY: clean fclean re all